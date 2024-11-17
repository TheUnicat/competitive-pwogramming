//
// Created by TheUnicat on 2024-11-10.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m, l;
        cin >> n >> m >> l;
        vector<pair<int, int>> hurdles, powerups;
        for (int j = 0; j < n; j++) {
            int left, right;
            cin >> left >> right;
            hurdles.emplace_back(left, right - left + 1);
        }
        for (int j = 0; j < m; j++) {
            int pos, val;
            cin >> pos >> val;
            powerups.emplace_back(pos, val);
        }

        priority_queue<int> powerup_pq;
        int jump = 1;
        int consumed_powerups = 0;
        int powerup_pos = 0;
        for (int j = 0; j < n; j++) {
            auto hurdle = hurdles[j];
            while (true) {
                if (powerup_pos == m) break;
                if (powerups[powerup_pos].first > hurdle.first) break;
                powerup_pq.push(powerups[powerup_pos].second);
                powerup_pos++;
            }

            if (jump > hurdle.second) continue;

            while (jump <= hurdle.second) {
                if (powerup_pq.empty()) break;
                jump += powerup_pq.top();
                consumed_powerups++;
                powerup_pq.pop();
            }

            if (jump <= hurdle.second) {
                consumed_powerups = -1;
                break;
            }
        }

        cout << consumed_powerups << endl;
    }
}