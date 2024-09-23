//
// Created by TheUnicat on 2024-09-23.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstdint>
using namespace std;

int h, w;
vector<vector<char>> meadow;

int main() {
    cin >> h >> w;
    meadow.resize(h, vector<char>(w));
    for (int i = 0; i < h; i++) {
        string line_one;
        cin >> line_one;

        for (int j = 0; j < w; j++) meadow[i][j] = line_one[j];
    }

    vector<vector<int>> min_distance(h, vector<int>(w, INT32_MAX));
    min_distance[0][0] = 0;
    deque<pair<int, int>> bfs;
    bfs.emplace_front(0, 0);
    while (!bfs.empty()) {
        auto pos = bfs.front();
        bfs.pop_front();
        char curr = meadow[pos.first][pos.second];
        int curr_dist = min_distance[pos.first][pos.second];
        if (pos.first != h - 1) {
            char next = meadow[pos.first + 1][pos.second];
            if (next != '.') {
                if (curr_dist + (next != curr) < min_distance[pos.first + 1][pos.second]) {
                    min_distance[pos.first + 1][pos.second] = curr_dist + (next != curr);
                    if (next == curr) bfs.emplace_front(pos.first + 1, pos.second);
                    else bfs.emplace_back(pos.first + 1, pos.second);
                }
            }
        }

        if (pos.first != 0) {
            char next = meadow[pos.first - 1][pos.second];
            if (next != '.') {
                if (curr_dist + (next != curr) < min_distance[pos.first - 1][pos.second]) {
                    min_distance[pos.first - 1][pos.second] = curr_dist + (next != curr);
                    if (next == curr) bfs.emplace_front(pos.first - 1, pos.second);
                    else bfs.emplace_back(pos.first - 1, pos.second);
                }
            }
        }

        if (pos.second != w - 1) {
            char next = meadow[pos.first][pos.second + 1];
            if (next != '.') {
                if (curr_dist + (next != curr) < min_distance[pos.first][pos.second + 1]) {
                    min_distance[pos.first][pos.second + 1] = curr_dist + (next != curr);
                    if (next == curr) bfs.emplace_front(pos.first, pos.second + 1);
                    else bfs.emplace_back(pos.first, pos.second + 1);
                }
            }
        }

        if (pos.second != 0) {
            char next = meadow[pos.first][pos.second - 1];
            if (next != '.') {
                if (curr_dist + (next != curr) < min_distance[pos.first][pos.second - 1]) {
                    min_distance[pos.first][pos.second - 1] = curr_dist + (next != curr);
                    if (next == curr) bfs.emplace_front(pos.first, pos.second - 1);
                    else bfs.emplace_back(pos.first, pos.second - 1);
                }
            }
        }
    }

    int min_animals = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (meadow[i][j] == '.') continue;
            min_animals = max(min_animals, min_distance[i][j]);
        }
    }

    cout << min_animals + 1;
}