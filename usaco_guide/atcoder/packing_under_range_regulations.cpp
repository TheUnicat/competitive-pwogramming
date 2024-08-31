//
// Created by TheUnicat on 2024-07-27.
//

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        map<int, vector<int> > l_sorted;

        for (int j = 0; j < n; j++) {
            int l, r;
            cin >> l >> r;
            l_sorted[l].push_back(r);
        }

        priority_queue<int, vector<int>, greater<int> > right_values;

        bool solvable = true;
        int current_num = (*l_sorted.begin()).first;
        auto it = l_sorted.begin();
        while (it != l_sorted.end()) {
            if ((*it).first <= current_num) {
                for (int num : (*it).second) right_values.push(num);
                it++;
            }
            else break;
        }

        while (true) {
            if (right_values.empty()) break;
            if (right_values.top() < current_num) {
                solvable = false;
                break;
            }
            right_values.pop();
            if (right_values.empty()) {
                auto next = l_sorted.upper_bound(current_num);
                if (next == l_sorted.end()) break;
                current_num = (*next).first;
            }
            else current_num++;
            while (it != l_sorted.end()) {
                if ((*it).first <= current_num) {
                    for (int num : (*it).second) right_values.push(num);
                    it++;
                }
                else break;
            }
        }

        if (solvable) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}