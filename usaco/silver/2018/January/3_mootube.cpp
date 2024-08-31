//
// Created by TheUnicat on 2024-08-03.
//

#include <fstream>
#include <vector>
using namespace std;

int n, q;
vector<vector<pair<int, int> > > graph;
int current_count;

void dfs_for_views(int node, int prev, int min_relevance) {
    for (pair<int, int> connection : graph[node]) {
        if (connection.second < min_relevance || connection.first == prev) continue;
        current_count++;
        dfs_for_views(connection.first, node, min_relevance);
    }
}

int main() {
    ifstream infile("mootube.in");
    ofstream outfile("mootube.out");
    infile >> n >> q;
    graph.resize(n, vector<pair<int, int> >());
    for (int i = 0; i < n - 1; i++) {
        int start, end, weight;
        infile >> start >> end >> weight;
        graph[start - 1].push_back(make_pair(end - 1, weight));
        graph[end - 1].push_back(make_pair(start - 1, weight));
    }

    for (int i = 0; i < q; i++) {
        int k, v;
        infile >> k >> v;
        current_count = 0;
        dfs_for_views(v - 1, -1, k);
        outfile << current_count << endl;
    }
    infile.close();
    outfile.close();
}