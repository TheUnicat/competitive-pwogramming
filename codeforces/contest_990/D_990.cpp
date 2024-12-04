//
// Created by TheUnicat on 2024-12-02.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> nums(n);
        vector<bool> to_be_modified(n, false);
        for (int j = 0; j < n; j++) cin >> nums[j];
        multiset<int> to_be_added;
        int curr_min = 1e9, min_removed = 1e9 + 1;
        for (int j = n - 1; j >= 0; j--) {
            if (nums[j] > curr_min) {
                to_be_modified[j] = true;
                to_be_added.insert(nums[j]);
                min_removed = min(min_removed, nums[j]);
            }
            else if (nums[j] < curr_min) curr_min = nums[j];
        }

        for (int j = 0; j < n; j++) {
            if (to_be_modified[j]) {
                continue;
            }
            else if (nums[j] > min_removed + 1) {
                to_be_modified[j] = true;
                to_be_added.insert(nums[j]);
            }
            else {
                cout << (nums[j]) << " ";
            }
        }

        auto it = to_be_added.begin();
        while (it != to_be_added.end()) {
            cout << ((*it) + 1) << " ";
            it++;
        }

        cout << endl;
    }
}
