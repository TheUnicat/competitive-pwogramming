//
// Created by TheUnicat on 2024-11-23.
//

#include <stack>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int n;
ll k, ans = 0;


int main() {
    cin >> n;
    vector<ll> fences(n);
    vector<pair<int, int>> fence_range(n);
    for (int i = 0; i < n; i++) {
        cin >> fences[i];
    }

    stack<pair<ll, int>> fence_stack;
    for (int i = 0; i < n; i++) {
        ll height = fences[i];
        while (!fence_stack.empty() && fence_stack.top().first >= height) {
            fence_stack.pop();
        }

        if (fence_stack.empty()) fence_range[i].first = 0;
        else fence_range[i].first = fence_stack.top().second;
        fence_stack.emplace(height, i + 1);
    }
    while (!fence_stack.empty()) fence_stack.pop();

    for (int i = n - 1; i >= 0; i--) {
        ll height = fences[i];
        while (!fence_stack.empty() && fence_stack.top().first >= height) {
            fence_stack.pop();
        }
        if (fence_stack.empty()) fence_range[i].second = n - 1;
        else fence_range[i].second = fence_stack.top().second;
        fence_stack.emplace(height, i - 1);
    }

    for (int i = 0; i < n; i++) {
        ans = max(ans, (fence_range[i].second - fence_range[i].first + 1) * fences[i]);
    }
    cout << ans;
}