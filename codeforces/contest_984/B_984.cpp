//
// Created by TheUnicat on 2024-11-02.
//

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int t;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        vector<int> brands;
        map<int, int> counts;
        vector<int> profits;
        for (int j = 0; j < k; j++) {
            int b, c;
            cin >> b >> c;
            brands.push_back(b);
            counts[b] += c;
        }

        int max_profit = 0;
        for (auto entry : brands) {
            profits.emplace_back(counts[entry]);
            counts[entry] = 0;
        }

        sort(profits.begin(), profits.end(), cmp);
        for (int j = 0; j < min(n, (int) profits.size()); j++) max_profit += profits[j];
        cout << max_profit << endl;
    }
}