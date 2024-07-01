//
// Created by TheUnicat on 2024-06-30.
//

#include <fstream>
#include <iostream>
using namespace std;

int n;

int main() {
    ifstream infile("div7.in");
    string line;
    getline(infile, line);
    n = stoi(line);
    int prefix_sum_mod_7[n + 1];
    prefix_sum_mod_7[0] = 0;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        getline(infile, line);
        sum += stoi(line);
        prefix_sum_mod_7[i + 1] = sum % 7;
        cout << sum % 7;
    }
    infile.close();

    int longest_distance = 0;

    for (int i = 0; i < 7; i++) {
        int min_index = -1;
        for (int j = 0; j <= n; j++) {
            if (prefix_sum_mod_7[j] == i) {
                min_index = j;
                break;
            }
        }
        if (min_index == -1) {
            continue;
        }

        int max_index = -1;
        for (int j = min_index + 1; j <= n; j++) {
            if (prefix_sum_mod_7[j] == i) {
                max_index = j;
            }
        }

        if (max_index == -1) {
            continue;
        }

        if (max_index - min_index > longest_distance) {
            longest_distance = max_index - min_index;
        }
    }

    ofstream outfile("div7.out");
    outfile << longest_distance;
    outfile.close();
}
