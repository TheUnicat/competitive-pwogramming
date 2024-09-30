//
// Created by TheUnicat on 2024-09-30.
//

#include <iostream>
#include <queue>
#include <vector>
using ll = long long;
using namespace std;

ll k;
deque<ll> bfs;
vector<ll> min_dist;
ll min_sum = 1e18;

int main() {
    cin >> k;
    bfs.push_back(1);
    min_dist.resize(k, INT32_MAX);
    min_dist[1] = 1;
    while (!bfs.empty()) {
        ll top = bfs.front();
        bfs.pop_front();
        if (min_dist[(top + 1) % k] > min_dist[top] + 1) {
            min_dist[(top + 1) % k] = min_dist[top] + 1;
            bfs.push_back((top + 1) % k);
        }

        if (min_dist[(top * 10) % k] > min_dist[top]) {
            min_dist[(top * 10) % k] = min_dist[top];
            bfs.push_front((top * 10) % k);
        }
    }

    cout << min_dist[0];
}