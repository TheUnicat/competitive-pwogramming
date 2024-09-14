//
// Created by TheUnicat on 2024-09-12.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l;
int max_l = 200000;
int num;
vector<int> longest_length(max_l, INT32_MAX);

int main() {
    cin >> l;
    for (int i = 0; i < l; i++) {
        cin >> num;
        auto it = lower_bound(longest_length.begin(), longest_length.end(), num);
        if (*it > num) longest_length[distance(longest_length.begin(), it)] = num;
    }

    auto longest = lower_bound(longest_length.begin(), longest_length.end(), INT32_MAX);
    cout << distance(longest_length.begin(), longest);
}