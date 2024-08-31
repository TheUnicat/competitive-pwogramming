//
// Created by TheUnicat on 2024-07-23.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, x;
vector<pair<int, int> > test_case;

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        test_case.push_back(make_pair(num, i + 1));
    }

    sort(test_case.begin(), test_case.end());

    for (int i = 0; i < n; i++) {
        int target = x - test_case[i].first;
        int left = 0, right = n - 1;
        while (right > left) {
            if (right == i) {
                right--;
            }
            else if (left == i) {
                left++;
            }
            else {
                int sum = test_case[left].first + test_case[right].first;
                if (sum == target) {
                    cout << test_case[i].second << " " << test_case[left].second << " " << test_case[right].second;
                    return 0;
                }
                else if (sum > target) {
                    right--;
                }
                else left++;
            }
        }
    }

    cout << "IMPOSSIBLE";
}