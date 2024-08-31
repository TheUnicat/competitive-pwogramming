//
// Created by TheUnicat on 2024-07-03.
//

#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int prefix_sums[1001][1001];
int good_tiles = 0;

int main() {
    ifstream infile("paintbarn.in");
    string line;
    getline(infile, line);
    int n, k;
    istringstream iss(line);
    iss >> n >> k;

    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) {
            prefix_sums[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        int start_x, start_y, end_x, end_y;
        getline(infile, line);
        istringstream iss_two(line);
        iss_two >> start_x >> start_y >> end_x >> end_y;
        prefix_sums[end_x][end_y]++;
        prefix_sums[start_x][end_y]--;
        prefix_sums[end_x][start_y]--;
        prefix_sums[start_x][start_y]++;

    }
    infile.close();

    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) {
            if (i > 0) prefix_sums[i][j] += prefix_sums[i - 1][j];
            if (j > 0) prefix_sums[i][j] += prefix_sums[i][j - 1];
            if (i > 0 & j > 0) prefix_sums[i][j] -= prefix_sums[i - 1][j - 1];
            good_tiles += prefix_sums[i][j] == k;
        }
    }

    ofstream outfile("paintbarn.out");
    outfile << good_tiles;
    outfile.close();
}