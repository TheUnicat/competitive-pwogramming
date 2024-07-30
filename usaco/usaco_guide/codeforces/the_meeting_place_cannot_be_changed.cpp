//
// Created by TheUnicat on 2024-07-30.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int n;

bool solution_valid(long double time, const vector<pair<int, int> > &friends) {
    long double l = friends[0].first - friends[0].second * time;
    long double r = friends[0].first + friends[0].second * time;

    for (auto values : friends) {
        long double friend_l = values.first - values.second * time;
        long double friend_r = values.first + values.second * time;

        l = max(l, friend_l);
        r = min(r, friend_r);

        if (r - l <= 0) return false;
    }

    return true;
}

int main() {
    cin >> n;
    vector<pair<int, int> > friends(n);
    cout << fixed << setprecision(15);

    for (int i = 0; i < n; i++) cin >> friends[i].first;
    for (int i = 0; i < n; i++) cin >> friends[i].second;

    sort(friends.begin(), friends.end());

    long double max_time = friends[n - 1].first - friends[0].first;
    long double min_time = 0;
    long double min_solution = max_time;

    while (max_time - 0.0000001 > min_time) {
        long double mid = min_time + (max_time - min_time) / 2;

        if (solution_valid(mid, friends)) {
            min_solution = mid;
            max_time = mid;
        }
        else {
            min_time = mid;
        }
    }

    cout << min_solution;
}