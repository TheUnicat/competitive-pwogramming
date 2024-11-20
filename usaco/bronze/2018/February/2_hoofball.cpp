//
// Created by TheUnicat on 2024-11-19.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans = 0;
vector<int> cows;
vector<int> successor_graph;
vector<int> indegrees;

void make_graph() {
    if (n == 1) return;
    for (int i = 0; i < n; i++) {
        int closest_cow;
        if (i == 0) closest_cow = 1;
        else if (i == n - 1) closest_cow = n - 2;
        else {
            if (cows[i + 1] - cows[i] < cows[i] - cows[i - 1]) closest_cow = i + 1;
            else closest_cow = i - 1;
        }
        successor_graph[i] = closest_cow;
        indegrees[closest_cow]++;
    }
}

int main() {
    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);
    cin >> n;
    cows.resize(n);
    indegrees.resize(n, 0);
    successor_graph.resize(n);
    for (int i = 0; i < n; i++) cin >> cows[i];

    sort(cows.begin(), cows.end());
    make_graph();

    for (int i = 0; i < n; i++) {
        if (indegrees[i] == 0) ans++;
        else if ((indegrees[i] == 1) && (indegrees[successor_graph[i]] == 1) && (successor_graph[successor_graph[i]] == i) && i < successor_graph[i]) ans++;
    }

    cout << ans << endl;
}

