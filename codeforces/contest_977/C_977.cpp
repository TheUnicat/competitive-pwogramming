//
// Created by TheUnicat on 2024-10-05.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m, q;
        bool possible = true;
        cin >> n >> m >> q;
        vector<int> init_ord(n);
        vector<int> nums(m);
        for (int j = 0; j < n; j++) cin >> init_ord[j];

        set<int> seen_nums;
        int curr_index = 0;
        for (int j = 0; j < m; j++) cin >> nums[j];
        for (int j = 0; j < m; j++) {
            int num = nums[j];
            if (seen_nums.find(num) == seen_nums.end()) {
                if (curr_index < n && num == init_ord[curr_index]) {
                    seen_nums.insert(init_ord[curr_index]);
                    curr_index++;
                    continue;
                }
                possible = false;
                break;
            }

        }

        if (possible) cout << "YA" << endl;
        else cout << "TIDAK" << endl;
    }
}