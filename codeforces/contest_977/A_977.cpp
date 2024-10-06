//
// Created by TheUnicat on 2024-10-05.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        priority_queue<int, vector<int>, greater<int>> nums;
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            nums.push(num);
        }

        while (nums.size() > 1) {
            int a = nums.top();
            nums.pop();
            int b = nums.top();
            nums.pop();
            nums.push((a + b) / 2);
        }

        cout << nums.top() << endl;
    }
}