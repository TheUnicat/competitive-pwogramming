//
// Created by TheUnicat on 2024-08-02.
//

#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, r;
vector<vector<bool> > cow_locations;
vector<pair<int, int> > cow_list;
vector<vector<vector<char> > > roads;
vector<vector<bool> > visited;
vector<int> cow_count_per_component;
int current_cow_count;

void floodfill(int x, int y) {
    if (x == -1 || x == n || y == -1 || y == n) return;
    if (visited[x][y]) return;

    visited[x][y] = true;
    if (cow_locations[x][y]) {
        cow_locations[x][y] = false;
        current_cow_count++;
    }
    vector<char> road = roads[x][y];
    if (find(road.begin(), road.end(), 'U') == road.end()) floodfill(x, y + 1);
    if (find(road.begin(), road.end(), 'D') == road.end())  floodfill(x, y - 1);
    if (find(road.begin(), road.end(), 'L') == road.end())  floodfill(x - 1, y);
    if (find(road.begin(), road.end(), 'R') == road.end())  floodfill(x + 1, y);
}

int main() {
    ifstream infile("countcross.in");
    infile >> n >> k >> r;
    cow_locations.resize(n, vector<bool>(n, false));
    roads.resize(n, vector<vector<char> >(n, vector<char>()));
    for (int i = 0; i < r; i++) {
        int l, r, l_1, r_1;
        infile >> l >> r >> l_1 >> r_1;
        if (l == l_1) {
            if (r > r_1) {
                roads[l - 1][r - 1].push_back('D');
                roads[l - 1][r_1 - 1].push_back('U');
            }
            else {
                roads[l - 1][r - 1].push_back('U');
                roads[l - 1][r_1 - 1].push_back('D');
            }
        }
        else {
            if (l > l_1) {
                roads[l - 1][r - 1].push_back('L');
                roads[l_1 - 1][r - 1].push_back('R');
            }
            else {
                roads[l - 1][r - 1].push_back('R');
                roads[l_1 - 1][r - 1].push_back('L');
            }
        }
    }
    for (int i = 0; i < k; i++) {
        int x, y;
        infile >> x >> y;
        cow_locations[x - 1][y - 1] = true;
        cow_list.push_back(make_pair(x - 1, y - 1));
    }
    infile.close();

    auto it = cow_list.begin();
    while (it != cow_list.end()) {
        pair<int, int> cow = *it;
        if (cow_locations[cow.first][cow.second]) {
            visited.clear();
            visited.resize(n, vector<bool>(n, false));
            current_cow_count = 0;
            floodfill(cow.first, cow.second);
            cow_count_per_component.push_back(current_cow_count);
        }
        it++;
    }

    int cow_pairs = 0;
    for (int component : cow_count_per_component) cow_pairs += component * (k - component);
    ofstream outfile("countcross.out");
    outfile << (cow_pairs / 2);
    outfile.close();
}