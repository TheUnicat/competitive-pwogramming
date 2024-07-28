//
// Created by TheUnicat on 2024-07-28.
//

#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

int n;

int main() {
    cin >> n;
    vector<pair<int, int> > tasks(n);
    for (int i = 0; i < n; i++) cin >> tasks[i].first >> tasks[i].second;
    sort(tasks.begin(), tasks.end());

    ll total_reward = 0;
    ll current_time = 0;
    for (pair<int, int> task : tasks) {
        current_time += task.first;
        total_reward += task.second - current_time;
    }

    cout << total_reward;
}