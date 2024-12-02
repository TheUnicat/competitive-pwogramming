//
// Created by TheUnicat on 2024-12-01.
//

#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

ll n, m;

int main() {
    freopen("hayfeast.in", "r", stdin);
    freopen("hayfeast.out", "w", stdout);
    cin >> n >> m;
    vector<pair<int, int>> bales(n);
    deque<ll> max_spiciness;
    for (int i = 0; i < n; i++) cin >> bales[i].first >> bales[i].second;
    ll curr_flavor = 0;
    int curr_right = 0;
    for (curr_right = 0; curr_right < n; curr_right++) {
        curr_flavor += bales[curr_right].first;
        while (!max_spiciness.empty() && max_spiciness.back() < bales[curr_right].second) {
            max_spiciness.pop_back();
        }
        max_spiciness.push_back(bales[curr_right].second);
        if (curr_flavor >= m) break;
    }
    ll min_spiciness = max_spiciness.front();
    for (int i = 1; i < n; i++) {
        curr_flavor -= bales[i - 1].first;
        if (max_spiciness.front() == bales[i - 1].second)  max_spiciness.pop_front();
        while (curr_flavor < m) {
            curr_right++;
            if (curr_right == n) break;
            curr_flavor += bales[curr_right].first;
            while (!max_spiciness.empty() && max_spiciness.back() < bales[curr_right].second) {
                max_spiciness.pop_back();
            }
            max_spiciness.push_back(bales[curr_right].second);
        }
        if (curr_flavor < m) break;
        min_spiciness = min(min_spiciness, max_spiciness.front());
    }

    cout << min_spiciness << endl;
}
