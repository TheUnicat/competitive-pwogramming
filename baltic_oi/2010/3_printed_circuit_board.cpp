//
// Created by TheUnicat on 2024-09-14.
//

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int n;
vector<pair<int, int>> connectors;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        connectors.emplace_back(l, r);
    }
    sort(connectors.begin(), connectors.end());
    vector<int> piles;
    for (auto connection : connectors) {
        int left = 0;
        int right = (int) piles.size() - 1;
        int min_index_less = INT32_MAX;
        while (right >= left) {
            int mid = left + (right - left) / 2;
            if (piles[mid] < connection.second) {
                min_index_less = min(min_index_less, mid);
                right = mid - 1;
            }
            else left = mid + 1;
        }

        if (min_index_less != INT32_MAX) piles[min_index_less] = connection.second;
        else piles.push_back(connection.second);
    }

    cout << piles.size();
}