//
// Created by TheUnicat on 2024-11-19.
//

#include <iostream>
#include <stack>
using namespace std;

int n;
stack<pair<int, int>> nums;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        while (!nums.empty() && nums.top().first >= num) {
            nums.pop();
        }
        if (nums.empty()) cout << 0 << " ";
        else cout << nums.top().second << " ";
        nums.emplace(num, i + 1);
    }
}