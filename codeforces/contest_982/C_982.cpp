//
// Created by TheUnicat on 2024-10-14.
//

#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        map<ll, vector<ll>> possible_nums;
        map<ll, bool> visited;
        ll n;
        cin >> n;

        for (int j = 0; j < n; j++) {
            ll num;
            cin >> num;
            possible_nums[j + num].push_back(j);
            visited[j + num] = false;
        }
        ll max_size = n;
        queue<ll> dfs;
        dfs.push(n);
        visited[n] = true;
        while (!dfs.empty()) {
            ll top = dfs.front();
            dfs.pop();
            for (ll val : possible_nums[top]) {
                if (visited[top + val]) continue;
                dfs.push(top + val);
                visited[top + val] = true;
                max_size = max(top + val, max_size);
            }
        }

        cout << max_size << endl;
    }
}