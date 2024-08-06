//
// Created by TheUnicat on 2024-08-05.
//

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> next_student;
vector<int> visited;

int u;

void dfs(int start) {
    if (visited[start] == 0) {
        u = start;
        return;
    }

    visited[start]++;
    dfs(next_student[start]);
}

int main() {
    cin >> n;
    next_student.resize(n);
    visited.resize(n, -2);
    for (int i = 0; i < n; i++) {
        cin >> next_student[i];
        next_student[i]--;
    }

    for (int i = 0; i < n; i++) {
        dfs(i);
        visited.clear();
        visited.resize(n, -2);
        cout << u + 1 << " ";
    }
}