//
// Created by TheUnicat on 2024-06-23.
//

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int n;
int final_count = 0;
bool in_sequence = false;

int main() {
    ifstream infile("breedflip.in");
    string line;
    getline(infile, line);
    istringstream iss(line);
    iss >> n;
    getline(infile, line);
    string a = line;
    getline(infile, line);
    string b = line;
    infile.close();

    for (int i = 0; i < n; i++) {
        if (not in_sequence) {
            if (a[i] != b[i]) {
                in_sequence = true;
                if (i == n - 1) {
                    final_count++;
                }
            }
        }
        else if (a[i] != b[i]) {
            if (i == n - 1) {
                final_count++;
            }
        }
        else {
            in_sequence = false;
            final_count++;
        }
    }

    ofstream outfile("breedflip.out");
    outfile << final_count;
    outfile.close();
}