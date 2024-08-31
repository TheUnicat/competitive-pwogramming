//
// Created by TheUnicat on 2024-08-02.
//

#include <fstream>
#include <vector>
#include <set>
#include <iostream>
#include <string>
using namespace std;

int n;
vector<string> farm;
int n_pcls = 0;
vector<pair<pair<int, int>, pair<int, int> > > found_pcls;
vector<vector<bool> > searched;

void floodfill(int x, int y, int min_x, int min_y, int k, int z, char c) {
    if (x < min_x || y < min_y || x >= k || y >= z || x == n || y == n) return;
    if (searched[x][y]) return;

    if (farm[x][y] != c) return;
    searched[x][y] = true;
    floodfill(x + 1, y, min_x, min_y, k, z,  c);
    floodfill(x - 1, y, min_x, min_y, k, z, c);
    floodfill(x, y + 1, min_x, min_y, k, z, c);
    floodfill(x, y - 1, min_x, min_y, k, z, c);
}


bool check_pcl(int x, int y, int k, int z) {
    for (auto pcl : found_pcls) {
        if (pcl.first.first <= x && pcl.first.second <= y && pcl.second.first >= k && pcl.second.second >= z) {
            return false;
        }
    }
    searched.clear();
    searched.resize(n, vector<bool>(n, false));
    int a_components = 0;
    int b_components = 0;
    set<char> seen_chars;
    for (int i = x; i < k; i++) {
        for (int j = y; j < z; j++) {
            seen_chars.insert(farm[i][j]);
            if (seen_chars.size() > 2) return false;
        }
    }

    for (int i = x; i < k; i++) {
        for (int j = y; j < z; j++) {
            if (searched[i][j] == false) {
                char c = farm[i][j];
                if (c == *seen_chars.begin()) a_components++;
                else b_components++;
                floodfill(i, j, x, y, k, z, c);
            }
        }
    }

    if ((a_components == 1 && b_components >= 2) || (b_components == 1 && a_components >= 2)) {
        for (int i = x; i < k; i++) {
            for (int j = y; j < z; j++) {
                seen_chars.insert(farm[i][j]);
            }
        }

        found_pcls.push_back(make_pair(make_pair(x, y), make_pair(k, z)));

        n_pcls++;
        return true;
    }

    return false;
}

int main() {
    ifstream infile("where.in");
    infile >> n;
    farm.resize(n);
    for (int i = 0; i < n; i++) infile >> farm[i];
    infile.close();


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = n; k > i; k--) {
                for (int z = n; z > j; z--) {
                    if (k - 3 < i && z - 3 < j) break;
                    check_pcl(i, j, k, z);
                }
            }
        }
    }


    ofstream outfile("where.out");
    outfile << n_pcls;
    outfile.close();
}