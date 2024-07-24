//
// Created by TheUnicat on 2024-07-23.
//

//
// Created by TheUnicat on 2024-07-23.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n, x;
map<int, bool> tested_sums;
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
        for (int j = i + 1; j < n; j++) {
            int target = x - test_case[i].first - test_case[j].first;
            if (tested_sums[target] == true) continue;
            tested_sums[target] = true;
            int left = 0, right = n - 1;
            while (right > left) {
                if (right == i || right == j) {
                    right--;
                }
                else if (left == i || left == j) {
                    left++;
                }
                else {
                    int sum = test_case[left].first + test_case[right].first;
                    if (sum == target) {
                        cout << test_case[i].second << " " << test_case[j].second << " " << test_case[left].second << " " << test_case[right].second;
                        return 0;
                    }
                    else if (sum > target) {
                        right--;
                    }
                    else {
                        if (2 * test_case[right].first < target) {
                            break;
                        }
                        left++;
                    }
                }
            }
        }
    }

    cout << "IMPOSSIBLE";
}
