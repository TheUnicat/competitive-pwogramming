//
// Created by TheUnicat on 2024-07-23.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int n, target;

int main() {
    cin >> n >> target;
    long solution_left = -1, solution_right = -1;
    vector<int> test(n);
    for (int i = 0; i < n; i++) cin >> test[i];
    vector<int> test_case = test;
    sort(test_case.begin(), test_case.end());
    int left = 0, right = n - 1;

    while (left < right) {
        int sum = test_case[right] + test_case[left];
        if (sum == target) {
            auto it = find(test.begin(), test.end(), test_case[left]);
            solution_left = distance(test.begin(), it);
            it = find(test.begin() + solution_left + 1, test.end(), test_case[right]);
            solution_right = distance(test.begin(), it);
            if (solution_right == n) {
                it = find(test.begin(), test.begin() + solution_left, test_case[right]);
                solution_right = distance(test.begin(), it);
            }
            break;
        }
        else if (sum < target) {
            left++;
        }
        else {
            right--;
        }
    }

    if (solution_left != -1) {
        cout << solution_left + 1 << " " << solution_right + 1;
    }
    else {
        cout << "IMPOSSIBLE";
    }
}