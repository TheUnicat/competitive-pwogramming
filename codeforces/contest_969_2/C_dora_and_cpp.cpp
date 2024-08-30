//
// Created by TheUnicat on 2024-08-30.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t;

int solve(vector<int> nums, int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    int gcd = a;

    for (int i = 0; i < nums.size(); i++) nums[i] %= gcd;
    sort(nums.begin(), nums.end());
    int sol = nums[nums.size() - 1] - nums[0];
    for (int i = 0; i < nums.size() - 1; i++) sol = min(sol, nums[i] - nums[i + 1] + gcd);

    return sol;
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> nums(n);
        for (int j = 0; j < n; j++) cin >> nums[j];

        cout << solve(nums, a, b) << endl;
    }
}
