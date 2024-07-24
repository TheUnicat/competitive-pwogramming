//
// Created by TheUnicat on 2024-07-24.
//

#include <set>
#include <iostream>
using namespace std;

int n, m;
set<int> cities;
set<int> towers;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int city;
        cin >> city;
        cities.insert(city);
    }
    for (int i = 0; i < m; i++) {
        int tower;
        cin >> tower;
        towers.insert(tower);
    }

    int min_r = 0;

    for (auto it = cities.begin(); it != cities.end(); it++) {
        int closest_tower;
        auto closest_tower_it = towers.lower_bound(*it);
        if (closest_tower_it == towers.end()) {
            closest_tower_it--;
        }
        closest_tower = abs(*closest_tower_it - *it);
        if (closest_tower_it != towers.begin()) {
            closest_tower_it--;
            if (*it - *closest_tower_it < closest_tower) {
                closest_tower = abs(*it - *closest_tower_it);
            }
        }

        if (closest_tower > min_r) min_r = closest_tower;
    }

    cout << min_r;
}