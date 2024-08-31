//
// Created by TheUnicat on 2024-08-01.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n, m;
vector<vector<char> > rooms;
vector<vector<bool> > visited;


void floodfill(int x, int y, char c) {
    if (x == -1 || x == n  || y == -1 || y == m) return;
    if (rooms[x][y] != c) return;
    if (visited[x][y]) return;
    visited[x][y] = true;

    floodfill(x + 1, y, c);
    floodfill(x - 1, y, c);
    floodfill(x, y + 1, c);
    floodfill(x, y - 1, c);
}

int main() {
    cin >> n >> m;
    rooms.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> rooms[i][j];
        }
    }

    int components = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                floodfill(i, j, rooms[i][j]);
                if (rooms[i][j] == '.') components++;
            }
        }
    }

    cout << components;
}