//
// Created by TheUnicat on 2024-08-22.
//

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
using ll = long long;

vector<ll> totients(1000002);

void totient_and_divisor_sum() {
    for (ll i = 1; i <= 1000001; i++) {
        totients[i] = i;
    }

    for (ll i = 2; i <= 1000001; i++) {
        if (totients[i] == i) {
            for (ll j = i; j <= 1000001; j += i) {
                totients[j] -= totients[j] / i;
            }
        }
    }

    for (ll i = 1; i <= 1000001; i++) {
        totients[i] = totients[i - 1] + totients[i];
    }
}

ll solve(ll num) {
    ll solution = 0;
    for (ll i = 1; i <= num; i++) {
        solution += 1LL * (totients[num / i] - 1) * i;
    }

    return solution;
}

ll n;

int main() {
    totient_and_divisor_sum();
    ifstream infile("input.txt");
    ofstream outfile("output.txt");
    infile >> n;
    while (n != 0) {
        outfile << solve(n) << endl;
        infile >> n;
    }
}