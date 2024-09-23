//
// Created by TheUnicat on 2024-09-22.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> candies;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int pos, t;
        cin >> pos >> t;
        candies.emplace_back(pos - t, pos + t);
    }
    sort(candies.begin(), candies.end(), cmp);

    vector<int> wagons;
    vector<int> candies_to_wagons(n);
    for (int i = 0; i < n; i++) {
        int r = candies[i].second;
        auto it = lower_bound(wagons.begin(), wagons.end(), r);
        if (it == wagons.end()) {
            wagons.push_back(r);
            candies_to_wagons[i] = (int) wagons.size();
        }
        else {
            *it = r;
            candies_to_wagons[i] = (int) distance(wagons.begin(), it) + 1;
        }
    }

    cout << wagons.size() << endl;
    for (int i = 0; i < n; i++) {
        auto candy = candies[i];
        cout << ((candy.first + candy.second) / 2) << " " << ((candy.second - candy.first) / 2) << " " << candies_to_wagons[i] << endl;
    }
}

// 1 1
// 1 5

// 1