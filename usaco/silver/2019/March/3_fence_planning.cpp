//
// Created by TheUnicat on 2024-07-31.
//

#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int n, m;
vector<vector<int> > cow_graph;
vector<pair<int, int> > cows;
vector<bool> visited;

vector<int> dfs(int start_node) {
    vector<int> new_cows;
    if (visited[start_node]) return new_cows;
    visited[start_node] = true;
    new_cows.push_back(start_node);

    for (int connection : cow_graph[start_node]) {
        vector<int> additions = dfs(connection);
        new_cows.insert(new_cows.end(), additions.begin(), additions.end());
    }

    return new_cows;
}

int main() {
    ifstream infile("fenceplan.in");
    infile >> n >> m;

    cows.resize(n);
    cow_graph.resize(n, vector<int>());

    for (int i = 0; i < n; i++) {
        infile >> cows[i].first >> cows[i].second;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        infile >> a >> b;
        cow_graph[a - 1].push_back(b - 1);
        cow_graph[b - 1].push_back(a - 1);
    }
    infile.close();

    ll min_perimeter = 10e10;

    visited.resize(n, false);
    auto it = visited.begin();
    while (it != visited.end()) {
        if (*it == false) {
            vector<int> new_moo_network = dfs(distance(visited.begin(), it));
            int max_x = -1;
            int max_y = -1;
            int min_x = 100000001;
            int min_y = 100000001;
            for (int i = 0; i < new_moo_network.size(); i++) {
                int x = cows[new_moo_network[i]].first;
                int y = cows[new_moo_network[i]].second;

                if (x > max_x) max_x = x;
                if (y > max_y) max_y = y;
                if (x < min_x) min_x = x;
                if (y < min_y) min_y = y;
            }

            ll perimeter = 2 * (max_x - min_x + max_y - min_y);
            if (perimeter < min_perimeter) min_perimeter = perimeter;
        }
        it++;
    }

    ofstream outfile("fenceplan.out");
    outfile << min_perimeter;
    outfile.close();
}