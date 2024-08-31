//
// Created by TheUnicat on 2024-08-03.
//

#include <fstream>
#include <vector>
using namespace std;

int n;
vector<int> cows;

int main() {
    ifstream infile("sleepy.in");
    infile >> n;
    cows.resize(n);
    for (int i = 0; i < n; i++) infile >> cows[i];
    infile.close();

    int sorted_cows = 0;
    for (int i = n - 1; i > 0; i--) {
        if (cows[i] > cows[i - 1]) sorted_cows++;
        else break;
    }

    ofstream outfile("sleepy.out");
    outfile << n - sorted_cows - 1;
    outfile.close();
}