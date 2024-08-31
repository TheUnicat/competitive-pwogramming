//
// Created by TheUnicat on 2024-08-28.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp (const pair<int, pair<int, int> > &a, const pair<int, pair<int, int> > &b) {
    return a.second.first < b.second.first;
}

int n, m;
vector<int> min_times(200000, 2000000000);

vector<vector<pair<int, pair<int, int> > > > connections(200000, vector<pair<int, pair<int, int> > >());

void dfs(int pos, int time) {
    min_times[pos] = min(min_times[pos], time);
    min_times[pos] = max(min_times[pos], 0);
    while (true) {
        if (connections[pos].empty()) break;

        pair<int, pair<int, int> > connection = connections[pos][connections[pos].size() - 1];
        if (connection.second.first < time && pos != 0) break;

        connections[pos].pop_back();
        if (connection.second.second >= min_times[connection.first]) continue;
        dfs(connection.first, connection.second.second);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int c, d, r, s;
        cin >> c >> r >> d >> s;

        connections[c - 1].push_back(make_pair(d - 1, make_pair(r, s)));
    }
    for (int i = 0; i < n; i++) {
        sort(connections[i].begin(), connections[i].end(), cmp);
        int layover_time;
        cin >> layover_time;
        for (int j = 0; j < connections[i].size(); j++) connections[i][j].second.first -= layover_time;
    }

    dfs(0, 0);

    for (int i = 0; i < n; i++) {
        if (min_times[i] == 2000000000) cout << -1 << endl;
        else cout << min_times[i] << endl;
    }
}