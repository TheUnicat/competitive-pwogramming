//
// Created by TheUnicat on 2024-06-30.
//

#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, k;

int main() {
    ifstream infile("stacking.in");
    string line;
    getline(infile, line);
    istringstream iss(line);
    iss >> n >> k;

    vector<int> bales(n, 0);

    for (int i = 0; i < k; i++) {
        getline(infile, line);
        int a, b;
        istringstream iss_two(line);
        iss_two >> a >> b;
        for (int j = a - 1; j <= b - 1; j++) {
            bales[j]++;
        }
    }
    infile.close();

    sort(bales.begin(), bales.end());

    ofstream outfile("stacking.out");
    int median = n / 2;
    outfile << bales[median];
    outfile.close();
}
