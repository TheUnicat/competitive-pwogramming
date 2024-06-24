//
// Created by TheUnicat on 2024-06-23.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
int swaps = 0;

vector<int> cows;

int main() {
    string line;
    ifstream infile("outofplace.in");
    getline(infile, line);
    n = stoi(line);

    for (int i = 0; i < n; i++) {
        getline(infile, line);
        cows.push_back(stoi(line));
    }
    infile.close();

    vector<int> sorted_cows = cows;
    sort(sorted_cows.begin(), sorted_cows.end());
    for (int i = 0; i < n; i++) {
        if (cows[i] != sorted_cows[i]) {
            swaps++;
        }
    }

    ofstream outfile("outofplace.out");
    outfile << swaps - 1;
    outfile.close();
}