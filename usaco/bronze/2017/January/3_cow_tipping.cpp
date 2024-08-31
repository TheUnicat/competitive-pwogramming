//
// Created by TheUnicat on 2024-06-25.
//

#include <fstream>
#include <vector>
#include <string>
using namespace std;

int n;
vector<vector<int> > cows;

void tip_cows(int x, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cows[i][j] == 1 ? cows[i][j] = 0 : cows[i][j] = 1;
        }
    }
}


int main() {
    ifstream infile("cowtip.in");
    string line;
    getline(infile, line);
    n = stoi(line);

    for (int i = 0; i < n; i++) {
        getline(infile, line);
        vector<int> cow_line;
        for (char character : line) {
            cow_line.push_back(character - '0');
        }
        cows.push_back(cow_line);
    }
    infile.close();

    int tips = 0;

    while (true) {
        int max_x = 0;
        int max_y = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cows[i][j] == 1) {
                    if (i >= max_x && (j >= max_y - 1 || max_y == 0)) {
                        max_x = i + 1;
                    }
                    if (j >= max_y) {
                        max_y = j + 1;
                    }
                }
            }
        }
        if (max_x == 0) {
            break;
        }
        tips++;
        tip_cows(max_x, max_y);
    }

    ofstream outfile("cowtip.out");
    outfile << tips;
    outfile.close();
}
