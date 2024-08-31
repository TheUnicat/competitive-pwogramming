//
// Created by TheUnicat on 2024-08-03.
//

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int> > graph;
vector<int> subordinate_count;

int n_subordinates(int employee) {
    int subordinates = 0;
    for (int subordinate : graph[employee]) {
        subordinates += n_subordinates(subordinate);
    }

    subordinate_count[employee] = subordinates;

    return subordinates + 1;
}

int main() {
    cin >> n;
    graph.resize(n, vector<int>());
    subordinate_count.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int superior;
        cin >> superior;
        graph[superior - 1].push_back(i + 1);
    }

    n_subordinates(0);
    for (int count : subordinate_count) cout << count << " ";
}