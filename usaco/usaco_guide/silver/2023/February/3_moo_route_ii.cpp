//
// Created by TheUnicat on 2024-08-28.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Comp {
    public:
        bool operator()(const pair<int, pair<int, int> > &a, const pair<int, pair<int, int> > &b) {
            return a.second.first < b.second.first;
        }
};

int n, m;
vector<int> layover_times(200000);
vector<int> min_times(200000, 2000000000);

vector<priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >,
Comp > > connections(200000, priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >,
Comp >());

void dfs(int pos, int time) {
    min_times[pos] = min(min_times[pos], time);
    min_times[pos] = max(min_times[pos], 0);
    while (true) {
        if (connections[pos].empty()) break;

        pair<int, pair<int, int> > connection = connections[pos].top();
        if (connection.second.first < time + layover_times[pos]) break;

        connections[pos].pop();
        if (connection.second.second >= min_times[connection.first]) continue;
        dfs(connection.first, connection.second.second);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int c, d, r, s;
        cin >> c >> r >> d >> s;

        connections[c - 1].emplace(make_pair(d - 1, make_pair(r, s)));
    }
    for (int i = 0; i < n; i++) cin >> layover_times[i];

    dfs(0, -1 * layover_times[0]);

    for (int i = 0; i < n; i++) {
        if (min_times[i] == 2000000000) cout << -1 << endl;
        else cout << min_times[i] << endl;
    }
}