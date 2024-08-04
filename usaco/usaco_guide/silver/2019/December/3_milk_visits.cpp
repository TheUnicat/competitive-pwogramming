//
// Created by TheUnicat on 2024-08-03.
//

#include <fstream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int n, m;
string farms;
vector<int> component_identities;
map<int, char> component_to_cow;
int current_component = 0;
vector<vector<int> > graph;

void dfs(int start, int prev, char c) {
    if (farms[start] != c) return;
    component_identities[start] = current_component;

    for (auto connection : graph[start]) {
        if (connection == prev) continue;
        dfs(connection, start, c);
    }
}

int main() {
    ifstream infile("milkvisits.in");
    ofstream outfile("milkvisits.out");
    infile >> n >> m;
    component_identities.resize(n, 0);
    graph.resize(n, vector<int>());
    infile >> farms;
    for (int i = 0; i < n - 1; i++) {
        int start, end;
        infile >> start >> end;
        graph[start - 1].push_back(end - 1);
        graph[end - 1].push_back(start - 1);
    }

    for (int i = 0; i < n; i++) {
        if (component_identities[i] == 0) {
            current_component++;
            dfs(i, -1, farms[i]);
            component_to_cow[current_component] = farms[i];
        }
    }

    for (int i = 0; i < m; i++) {
        int start, end;
        char milk;
        infile >> start >> end >> milk;
        if (component_identities[start - 1] != component_identities[end - 1] || component_to_cow[component_identities[start - 1]] == milk) outfile << 1;
        else outfile << 0;
    }
}