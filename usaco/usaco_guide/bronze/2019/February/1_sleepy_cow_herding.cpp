//
// Created by TheUnicat on 2024-08-03.
//

#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ifstream infile("herding.in");
    vector<int> cows(3);
    infile >> cows[0] >> cows[1] >> cows[2];
    infile.close();
    sort(cows.begin(), cows.end());
    int a = cows[0], b = cows[1], c = cows[2];
    int min_moves, max_moves;

    if (b - a == 1 && c - b == 1) {
        min_moves = 0;
        max_moves = 0;
    }
    else if (b - a == 2 || c - b == 2) {
        min_moves = 1;
        max_moves = max(b - a, c - b) - 1;
    }
    else {
        min_moves = 2;
        max_moves = max(b - a, c - b) - 1;
    }

    ofstream outfile("herding.out");
    outfile << min_moves << endl << max_moves;
    outfile.close();
}