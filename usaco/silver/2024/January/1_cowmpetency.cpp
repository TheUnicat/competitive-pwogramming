//
// Created by TheUnicat on 2024-09-03.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        bool unsolvable = false;
        int n, q, c;
        cin >> n >> q >> c;
        vector<int> competencies(n);
        vector<int> prefix_max(n);
        vector<int> suffix_min(n);
        vector<pair<int, int>> strictly_greater(q);
        int max_competency = 0;
        for (int j = 0; j < n; j++) {
            cin >> competencies[j];
            prefix_max[j] = max_competency;
            max_competency = max(max_competency, competencies[j]);
        }

        for (int j = 0; j < q; j++) {
            cin >> strictly_greater[j].first >> strictly_greater[j].second;
        }
        sort(strictly_greater.begin(), strictly_greater.end());

        int curr_min = 1;
        int curr_pos = 0;
        for (auto rule : strictly_greater) {
            if (unsolvable) break;
            for (int j = curr_pos; j < rule.first; j++) {
                curr_min = max(curr_min, competencies[j]);
            }

            if (competencies[rule.second - 1] == 0) competencies[rule.second - 1] = curr_min + 1;
            else if (competencies[rule.second - 1] <= curr_min) unsolvable = true;
        }

        if (unsolvable) {
            cout << -1 << endl;
            continue;
        }

        for (int j = 0; j < n; j++) {
            if (competencies[j] == 0) competencies[j] = 1;
            cout << competencies[j] << " ";
        }
        cout << endl;
    }
}