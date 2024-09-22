//
// Created by TheUnicat on 2024-09-20.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;

int n;
int num;

int main() {
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> lis(n, INT32_MAX);
    lis[0] = -1;

    for (int i = 0; i < n; i++) {
        cin >> num;
        a[num - 1] = i;
    }

    for (int i = 0; i < n; i++) {
        cin >> num;
        int val = a[num - 1];
        auto it = lower_bound(lis.begin(), lis.end(), val);
        lis[distance(lis.begin(), it)] = val;
    }

    auto it = lower_bound(lis.begin(), lis.end(), INT32_MAX);

    cout << distance(lis.begin(), it) - 1;
}