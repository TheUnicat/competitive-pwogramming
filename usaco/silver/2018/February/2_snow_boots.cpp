//
// Created by TheUnicat on 2024-08-03.
//

#include <fstream>
#include <vector>
using namespace std;

int n, b;
vector<int> path;
vector<pair<int, int> > boots;
vector<vector<bool> > visited;

void dfs(int path_index, int boot_index) {
    if (visited[path_index][boot_index]) return;
    visited[path_index][boot_index] = true;
    if (path_index == n - 1) return;
    if (boots[boot_index].first < path[path_index]) return;

    for (int i = boot_index + 1; i < b; i++) {
        dfs(path_index, i);
    }

    for (int i = min(n - 1, path_index + boots[boot_index].second); i > path_index; i--) {
        if (path[path_index] <= boots[boot_index].first) dfs(i, boot_index);
    }
}

int main() {
    ifstream infile("snowboots.in");
    infile >> n >> b;
    path.resize(n);
    boots.resize(b);
    visited.resize(n, vector<bool>(b, false));
    for (int i = 0; i < n; i++) infile >> path[i];
    for (int i = 0; i < b; i++) infile >> boots[i].first >> boots[i].second;
    infile.close();

    dfs(0, 0);

    int min_boot;
    for (int i = 0; i < b; i++) {
        if (visited[n - 1][i]) {
            min_boot = i;
            break;
        }
    }

    ofstream outfile("snowboots.out");
    outfile << min_boot;
    outfile.close();
}