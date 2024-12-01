//
// Created by TheUnicat on 2024-11-30.
//

#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

multiset<int> window_lower, window_upper;
vector<int> nums, first_k;
int n, k;

int main() {
    cin >> n >> k;
    nums.resize(n);
    first_k.resize(k);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < k; i++) first_k[i] = nums[i];
    sort(first_k.begin(), first_k.end());
    int lower_size = k / 2 + (k & 1);

    for (int i = 0; i < lower_size; i++) window_lower.insert(first_k[i]);
    for (int i = lower_size; i < k; i++) window_upper.insert(first_k[i]);

    auto it = window_lower.end();
    it--;
    cout << *it << " ";
    //cout << "uwu" << endl;
    for (int i = 1; i < n - k + 1; i++) {
        if (window_upper.find(nums[i - 1]) != window_upper.end()) {
            window_upper.erase(window_upper.find(nums[i - 1]));
            if (*(window_upper.begin()) <= nums[i + k - 1]) {
                window_upper.insert(nums[i + k - 1]);
            }
            else {
                window_lower.insert(nums[i + k - 1]);
                auto highest = window_lower.end();
                highest--;
                window_upper.insert(*highest);
                window_lower.erase(highest);
            }
        }
        else {
            //cout << "owo" << endl;
            window_lower.erase(window_lower.find(nums[i - 1]));
            auto highest = window_lower.end();
            if (!window_lower.empty()) highest--;
            //cout << ">w<" << endl;
            if (window_lower.empty() || *highest >= nums[i + k - 1]) {
                window_lower.insert(nums[i + k - 1]);
            }
            else {
                window_upper.insert(nums[i + k - 1]);
                window_lower.insert(*window_upper.begin());
                window_upper.erase(window_upper.begin());
            }
        }
        auto median = window_lower.end();
        median--;
        if (!window_upper.empty() && *median > *window_upper.begin()) {
            int first = *median, second = *window_upper.begin();
            window_lower.erase(median);
            window_upper.erase(window_upper.begin());
            window_upper.insert(first);
            window_lower.insert(second);
        }
        median = window_lower.end();
        median--;
        cout << *median << " ";
    }
}