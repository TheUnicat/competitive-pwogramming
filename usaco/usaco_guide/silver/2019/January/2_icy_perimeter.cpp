//
// Created by TheUnicat on 2024-08-01.
//

#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<char> > icecream;
vector<vector<bool> > visited;
vector<vector<pair<int, int> > > components;
vector<pair<int, int> > current_component;


int find_perimeter(const vector<pair<int, int> > &blob) {
    int perimeter = 0;
    for (auto cell : blob) {
        if (cell.first == 0 || icecream[cell.first - 1][cell.second] == '.') perimeter++;
        if (cell.first == n - 1 || icecream[cell.first + 1][cell.second] == '.') perimeter++;
        if (cell.second == 0 || icecream[cell.first][cell.second - 1] == '.') perimeter++;
        if (cell.second == n - 1 || icecream[cell.first][cell.second + 1] == '.') perimeter++;
    }

    return perimeter;
}

bool cmp(const vector<pair<int, int> > &a, const vector<pair<int, int> > &b) {
    return a.size() > b.size();
}

bool cmp_two(const vector<pair<int, int> > &a, const vector<pair<int, int> > &b) {
    return find_perimeter(a) < find_perimeter(b);
}


void floodfill(int x, int y, char c) {
    if (x == -1 || x == n || y == -1 || y == n) return;
    if (icecream[x][y] != c) return;
    if (visited[x][y]) return;
    visited[x][y] = true;
    current_component.push_back(make_pair(x, y));

    floodfill(x + 1, y, c);
    floodfill(x - 1, y, c);
    floodfill(x, y + 1, c);
    floodfill(x, y - 1, c);
}

int main() {
    ifstream infile("perimeter.in");
    infile >> n;
    icecream.resize(n, vector<char>(n));
    visited.resize(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            infile >> icecream[i][j];
        }
    }
    infile.close();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                current_component.clear();
                floodfill(i, j, icecream[i][j]);
                if (icecream[i][j] == '#') {
                    components.push_back(current_component);
                }
            }
        }
    }

    sort(components.begin(), components.end(), cmp);
    auto it = components.begin();
    while ((*it).size() == components[0].size()) it++;
    sort(components.begin(), it, cmp_two);

    ofstream outfile("perimeter.out");
    outfile << components[0].size() << " " << find_perimeter(components[0]);
    outfile.close();
}