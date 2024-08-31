//
// Created by TheUnicat on 2024-07-31.
//

#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<pair<pair<int, int>, int> > cows;
vector<vector<int> > graph;
vector<bool> searched;

int dfs_count(int start_node) {
    int count = 0;
    if (searched[start_node]) return count;
    searched[start_node] = true;
    count++;

    for (int edge : graph[start_node]) {
        count += dfs_count(edge);
    }

    return count;
}

int main() {
    ifstream infile("moocast.in");
    infile >> n;
    graph.resize(n, vector<int>());
    for (int i = 0; i < n; i++) {
        int x, y, p;
        infile >> x >> y >> p;
        cows.push_back(make_pair(make_pair(x, y), p));
    }
    infile.close();

    for (int i = 0; i < n; i++) {
        int x = cows[i].first.first;
        int y = cows[i].first.second;
        int p = cows[i].second;

        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            int x_gap = abs(cows[j].first.first - x);
            int y_gap = abs(cows[j].first.second - y);
            if (sqrt(x_gap * x_gap + y_gap * y_gap) <= p) {
                graph[i].push_back(j);
            }
        }
    }

    int max_cows_reached = 0;
    for (int i = 0; i < n; i++) {
        searched.clear();
        searched.resize(n, false);
        int cows_reached = dfs_count(i);
        if (cows_reached > max_cows_reached) max_cows_reached = cows_reached;
    }

    ofstream outfile("moocast.out");
    outfile << max_cows_reached;
    outfile.close();
}