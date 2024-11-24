//
// Created by TheUnicat on 2024-11-24.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int n;
vector<int> plates;

bool test_prefix(int len) {
    priority_queue<int> smallest_dish;
    vector<stack<int>> dish_stacks;
    for (int i = 0; i < len; i++) {
        smallest_dish.push(-plates[i]);
    }

    int done_idx = 0;
    for (int i = 0; i < len; i++) {
        if (-smallest_dish.top() == plates[i]) {
            smallest_dish.pop();
            continue;
        }
        else {
            while (done_idx < dish_stacks.size() && !dish_stacks[done_idx].empty() && dish_stacks[done_idx].top() == -smallest_dish.top()) {
                smallest_dish.pop();
                dish_stacks[done_idx].pop();
                if (dish_stacks[done_idx].empty()) done_idx++;
            }
            int min_stack = done_idx;
            int max_stack = dish_stacks.size() - 1;
            int ans = -1;
            while (max_stack >= min_stack) {
                int mid = min_stack + (max_stack - min_stack) / 2;
                if (dish_stacks[mid].top() > plates[i]) {
                    max_stack = mid - 1;
                    ans = mid;
                } else min_stack = mid + 1;
            }

            if (ans == -1) {
                stack<int> new_stack;
                new_stack.push(plates[i]);
                dish_stacks.push_back(new_stack);
            }
            else {
                dish_stacks[ans].push(plates[i]);
            }
        }
    }

    while (!smallest_dish.empty() &&done_idx < dish_stacks.size() && !dish_stacks[done_idx].empty() && dish_stacks[done_idx].top() == -smallest_dish.top()) {
        smallest_dish.pop();
        dish_stacks[done_idx].pop();
        if (dish_stacks[done_idx].empty()) done_idx++;
    }

    if (smallest_dish.empty()) return true;
    return false;
}

int main() {
    freopen("dishes.in", "r", stdin);
    freopen("dishes.out", "w", stdout);
    cin >> n;
    plates.resize(n);
    for (int i = 0; i < n; i++) cin >> plates[i];

    int min_idx = 1;
    int max_idx = n;
    int ans = -1;
    while (max_idx >= min_idx) {
        int mid = min_idx + (max_idx - min_idx) / 2;
        if (test_prefix(mid)) {
            min_idx = mid + 1;
            ans = mid;
        } else max_idx = mid - 1;
    }

    cout << ans << endl;
}