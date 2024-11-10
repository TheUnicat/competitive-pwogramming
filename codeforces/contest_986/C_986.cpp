//
// Created by TheUnicat on 2024-11-10.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll t;
vector<ll> cake_pieces_starting_from_n_reversed;

int main() {
    cin >> t;
    for (ll i = 0; i < t; i++) {
        ll n, m, v;
        cin >> n >> m >> v;
        vector<ll> cake(n);
        vector<ll> cake_pieces_starting_from_n(n, -1);
        vector<ll> cake_pieces_ending_n(n, -1);
        vector<ll> cake_tastiness_prefix(n);
        for (ll j = 0; j < n; j++) cin >> cake[j];
        cake_tastiness_prefix[0] = cake[0];
        for (ll j = 1; j < n; j++) cake_tastiness_prefix[j] = cake_tastiness_prefix[j - 1] + cake[j];

        ll cake_pieces = 0;
        ll counter = 0;
        for (ll j = 0; j < n; j++) {
            counter += cake[j];
            if (counter >= v) {
                counter = 0;
                cake_pieces++;
            }
            cake_pieces_ending_n[j] = cake_pieces;
        }

        cake_pieces = 0;
        counter = 0;
        for (ll j = n - 1; j >= 0; j--) {
            counter += cake[j];
            if (counter >= v) {
                counter = 0;
                cake_pieces++;
            }
            cake_pieces_starting_from_n[j] = cake_pieces;
        }

        cake_pieces_starting_from_n_reversed = cake_pieces_starting_from_n;
        reverse(cake_pieces_starting_from_n_reversed.begin(), cake_pieces_starting_from_n_reversed.end());

        bool solvable = false;
        if (cake_pieces_starting_from_n[0] >= m) solvable = true;
        ll max_alice = 0;
        for (ll j = -1; j < n - 1; j++) {
            ll pieces_already;
            if (j != -1) pieces_already = cake_pieces_ending_n[j];
            else pieces_already = 0;
            ll end_index = n - 2 - distance(cake_pieces_starting_from_n_reversed.begin(), lower_bound(cake_pieces_starting_from_n_reversed.begin(), cake_pieces_starting_from_n_reversed.end(), m - pieces_already));
            if (pieces_already >= m) end_index = n - 1;

            if (j != -1 && end_index >= 0) max_alice = max(max_alice, cake_tastiness_prefix[end_index] - cake_tastiness_prefix[j]);
            else if (end_index < 0) continue;
            else max_alice = max(max_alice, cake_tastiness_prefix[end_index]);
        }

        if (!solvable) cout << "-1" << endl;
        else cout << max_alice << endl;
    }
}