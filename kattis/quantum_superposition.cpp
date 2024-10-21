//
// Created by TheUnicat on 2024-10-18.
//

#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;

int n1, n2, m1, m2;
int u, v;
int max_size = 2001;
vector<vector<int>> graph1, graph2;
vector<int> indegree1, indegree2;
vector<int> sorted1, sorted2;
vector<bool> possible_sums(5000, false);
//max path length is 2000
vector<bitset<2001>> possible_lens1, possible_lens2;


int main() {
    cin >> n1 >> n2 >> m1 >> m2;
    graph1.resize(n1);
    graph2.resize(n2);
    indegree1.resize(n1, 0);
    indegree2.resize(n2, 0);

    possible_lens1.resize(n1);
    possible_lens2.resize(n2);
    possible_lens1[0][0] = true;
    possible_lens2[0][0] = true;

    for (int i = 0; i < m1; i++) {
        cin >> u >> v;
        graph1[u - 1].push_back(v - 1);
        indegree1[v - 1]++;
    }

    for (int i = 0; i < m2; i++) {
        cin >> u >> v;
        graph2[u - 1].push_back(v - 1);
        indegree2[v - 1]++;
    }

    queue<int> kahn1;
    for (int i = 0; i < n1; i++) {
        if (indegree1[i] == 0) {
            kahn1.push(i);
        }
    }

    while (!kahn1.empty()) {
        int top = kahn1.front();
        kahn1.pop();
        sorted1.push_back(top);
        for (int node : graph1[top]) {
            indegree1[node]--;
            if (indegree1[node] == 0) {
                kahn1.push(node);
            }
        }
    }

    queue<int> kahn2;
    for (int i = 0; i < n2; i++) {
        if (indegree2[i] == 0) {
            kahn2.push(i);
        }
    }

    while (!kahn2.empty()) {
        int top = kahn2.front();
        kahn2.pop();
        sorted2.push_back(top);
        for (int node : graph2[top]) {
            indegree2[node]--;
            if (indegree2[node] == 0) {
                kahn2.push(node);
            }
        }
    }

    for (int i = 0; i < n1; i++) {
        for (int node : graph1[sorted1[i]]) {
            for (size_t j = possible_lens1[sorted1[i]]._Find_first(); j < possible_lens1[sorted1[i]].size(); j = possible_lens1[sorted1[i]]._Find_next(j)) {
                possible_lens1[node][j + 1] = true;
            }
        }
    }

    for (int i = 0; i < n2; i++) {
        for (int node : graph2[sorted2[i]]) {
            for (size_t j = possible_lens2[sorted2[i]]._Find_first(); j < possible_lens2[sorted2[i]].size(); j = possible_lens2[sorted2[i]]._Find_next(j)) {
                possible_lens2[node][j + 1] = true;
            }
        }
    }

    for (size_t i = possible_lens1[n1 - 1]._Find_first(); i < possible_lens1[n1 - 1].size(); i = possible_lens1[n1 - 1]._Find_next(i)) {
        if (possible_lens1[n1 - 1][i]) {
            for (size_t j = possible_lens2[n2 - 1]._Find_first(); j < possible_lens2[n2 - 1].size(); j = possible_lens2[n2 - 1]._Find_next(j)) {
                possible_sums[i + j] = true;
            }
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int num;
        cin >> num;

        if (possible_sums[num]) cout << "Yes";
        else cout << "No";
        cout << endl;
    }
}