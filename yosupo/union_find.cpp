//
// Created by TheUnicat on 2024-10-01.
//

#include <iostream>
using namespace std;

int n, q;

int graph[200000];

void init() {
    for (int i = 0; i < n; i++) graph[i] = i;
}

int find_group(int a) {
    if (graph[a] == a) return a;
    graph[a] = find_group(graph[a]);
    return graph[a];
}

void unite(int a, int b) {
    int a_group = find_group(a);
    int b_group = find_group(b);
    if (a_group != b_group) {
        if (a & 2) graph[a_group] = b_group;
        else graph[b_group] = a_group;
    }
}

int main() {
    cin >> n >> q;
    init();
    for (int i = 0; i < q; i++) {
        int mode, a, b;
        cin >> mode >> a >> b;
        if (mode == 0) unite(a, b);
        else {
            cout << (find_group(a) == find_group(b)) << endl;
        }
    }
}