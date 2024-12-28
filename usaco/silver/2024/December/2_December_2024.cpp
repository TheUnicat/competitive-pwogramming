#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int t, n, k;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int cut = 0;
        cin >> n >> k;
        vector<int> trees(n);
        vector<pair<pair<int, int>, int>> rules;
        for (int j = 0; j < n; j++) cin >> trees[j];
        sort(trees.begin(), trees.end());
        for (int j = 0; j < k; j++) {
            int l, r, min_trees;
            cin >> l >> r >> min_trees;
            int left_idx = (int) distance(trees.begin(), lower_bound(trees.begin(), trees.end(), l));
            int right_idx = (int) distance(trees.begin(), upper_bound(trees.begin(), trees.end(), r));
            rules.emplace_back(make_pair(left_idx, right_idx), min_trees);
            //cout << left_idx << " " << right_idx << " " << min_trees << endl;
        }
        sort(rules.begin(), rules.end());

        multiset<int> minimums;
        multiset<pair<int, int>> endings;
        int curr_rule = 0;
        for (int j = 0; j < n; j++) {
            while (curr_rule != k && rules[curr_rule].first.first == j) {
                int can_be_cut = rules[curr_rule].first.second - rules[curr_rule].first.first - rules[curr_rule].second;
                minimums.insert(can_be_cut + cut);
                //cout << can_be_cut + cut << endl;
                endings.emplace(rules[curr_rule].first.second, can_be_cut + cut);
                curr_rule++;
            }
            while (!endings.empty() && (*endings.begin()).first == j) {
                minimums.erase(minimums.find((*endings.begin()).second));
                endings.erase(endings.begin());
            }

            int curr_max;
            if (!minimums.empty()) curr_max = (*minimums.begin());
            else curr_max = 1e9;
            if (curr_max > cut) cut++;
            //cout << cut << " ";
        }

        cout << cut << endl;
    }
}

//1 2 3 4 5 6 7