//
// Created by TheUnicat on 2024-09-23.
//

#include <iostream>
#include <string>
#include <queue>
#include <cstdint>
#include <vector>
using namespace std;

int n, m;
pair<int, int> a_pos, b_pos;
vector<pair<int, int>> movements{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool inside(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

int main() {
    cin >> n >> m;
    vector<vector<char>> labyrinth(n, vector<char>(m));
    vector<vector<int>> min_distances(n, vector<int>(m, INT32_MAX));
    vector<vector<char>> prev_move(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++) {
            labyrinth[i][j] = line[j];
            if (line[j] == 'A') a_pos = make_pair(i, j);
            else if (line[j] == 'B') b_pos = make_pair(i, j);
        }
    }

    min_distances[a_pos.first][a_pos.second] = 0;
    queue<pair<int, int>> bfs;
    bfs.push(a_pos);

    while (!bfs.empty()) {
        auto pos = bfs.front();
        bfs.pop();
        int curr_dist = min_distances[pos.first][pos.second];
        for (int i = 0; i < 4; i++) {
            auto movement = movements[i];
            int new_x = pos.first + movement.first, new_y = pos.second + movement.second;
            if (!inside(new_x, new_y)) continue;
            if (labyrinth[new_x][new_y] == '#') continue;
            if (curr_dist + 1 < min_distances[new_x][new_y]) {
                min_distances[new_x][new_y] = curr_dist + 1;
                prev_move[new_x][new_y] = i == 0 ? 'U' : i == 1 ? 'D' : i == 2 ? 'L' : 'R';
                bfs.emplace(new_x, new_y);
            }
        }
    }

    if (min_distances[b_pos.first][b_pos.second] == INT32_MAX) {
        cout << "NO";
    }
    else {
        cout << "YES" << endl;
        cout << min_distances[b_pos.first][b_pos.second] << endl;
        string answer_string;
        while (b_pos != a_pos) {
            char move = prev_move[b_pos.first][b_pos.second];
            answer_string += move;
            if (move == 'L') b_pos.second++;
            else if (move == 'R') b_pos.second--;
            else if (move == 'U') b_pos.first++;
            else b_pos.first--;
        }
        for (int i = (int) answer_string.length() - 1; i >= 0; i--) cout << answer_string[i];
    }
}