//
// Created by TheUnicat on 2024-09-14.
//

#include <fstream>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int n;
int layers = 0;
vector<pair<int, int>> connectors_temp;
vector<int> connectors;
vector<bool> done;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        connectors_temp.emplace_back(l, r);
        done.push_back(false);
    }
    sort(connectors_temp.begin(), connectors_temp.end(), cmp);
    for (auto thing : connectors_temp) connectors.push_back(thing.second);

    vector<int> piles;
    for (int connection : connectors) {
        int left = 0;
        int right = (int) piles.size() - 1;
        int min_index_less = INT32_MAX;
        while (right >= left) {
            int mid = left + (right - left) / 2;
            if (piles[mid] < connection) {
                min_index_less = min(min_index_less, mid);
                right = mid - 1;
            }
            else left = mid + 1;
        }

        if (min_index_less != INT32_MAX) piles[min_index_less] = connection;
        else piles.push_back(connection);
    }

    cout << piles.size();
}