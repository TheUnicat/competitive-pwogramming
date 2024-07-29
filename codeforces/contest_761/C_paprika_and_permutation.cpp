//
// Created by TheUnicat on 2024-07-29.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> numbers;
        set<int> unmatched;
        for (int j = 0; j < n; j++) unmatched.insert( j + 1);
        int num;
        int operations = 0;

        for (int j = 0; j < n; j++) {
            cin >> num;
            if (num <= n) {
                auto it = unmatched.lower_bound(num);
                if (it != unmatched.end()) {
                    if (*it == num) {
                        unmatched.erase(it);
                        continue;
                    }
                    else numbers.push_back(num);
                }
                else numbers.push_back(num);
            }
            else numbers.push_back(num);
        }

        sort(numbers.begin(), numbers.end());
        auto it = unmatched.begin();

        for (int j = 0; j < numbers.size(); j++) {
            int target = *it;
            num = numbers[j];
            if (num - target <= target) {
                operations = -1;
                break;
            }

            operations++;
            it++;
        }

        cout << operations << endl;
    }
}