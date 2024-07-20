//
// Created by TheUnicat on 2024-07-19.
//

#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<bool> visited;
int n, m;

bool sort_wormholes(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.second < b.second;
}


bool dfs(const vector<vector<pair<int, int> > > &wormhole_graph, int start_node, int end_node, int min_width) {
    //cout << start_node << " " << end_node << endl;
    if (visited.size() != wormhole_graph.size()) visited.resize(wormhole_graph.size(), false);
    visited[start_node] = true;

    for (auto edge : wormhole_graph[start_node]) {
        if (edge.first == end_node && edge.second >= min_width) {
            return true;
        }
        //else if (edge.second >= min_width); cout << "destination: " << edge.first << endl;
    }

    for (auto edge : wormhole_graph[start_node]) {
        if (visited[edge.first] || edge.second < min_width) continue;
        if (dfs(wormhole_graph, edge.first, end_node, min_width)) return true;
    }
    return false;
}

bool test_case(const vector<int> &cows, const vector<vector<pair<int, int> > > &wormhole_graph, int min_width) {
    for (int i = 0; i < cows.size(); i++) {
        if (cows[i] == i + 1) continue;
        visited.clear();
        //cout << endl << endl << min_width << endl;
        if (!dfs(wormhole_graph, i, cows[i] - 1, min_width)) {
            //cout << "doesn't work" << endl;
            return false;
        }
    }
    return true;
}


int main() {
    ifstream infile("wormsort.in");
    infile >> n >> m;
    vector<int> cows(n);
    vector<pair<pair<int, int>, int> > wormholes(m);
    vector<vector<pair<int, int> > > wormhole_graph(n);
    for (int i = 0; i < n; i++) infile >> cows[i];
    for (int i = 0; i < m; i++) {
        int x, y, w;
        infile >> x >> y >> w;
        wormholes[i] = make_pair(make_pair(x, y), w);
        wormhole_graph[x - 1].push_back(make_pair(y - 1, w));
        wormhole_graph[y - 1].push_back(make_pair(x - 1, w));
    }
    infile.close();
    sort(wormholes.begin(), wormholes.end(), sort_wormholes);

    int min_width = wormholes[0].second;
    //cout << "initial width" << min_width << endl;
    for (int i = 1; i < m; i++) {
        if (test_case(cows, wormhole_graph, wormholes[i].second)) {
            min_width = wormholes[i].second;
        }
        else break;
    }
    bool already_sorted = true;
    for (int i = 0; i < n; i++) {
        if (cows[i] - 1 != i) {
            already_sorted = false;
            break;
        }
    }
    if (already_sorted) min_width = -1;
    ofstream outfile("wormsort.out");
    outfile << min_width;
    outfile.close();
}
