//
// Created by TheUnicat on 2024-06-13.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ifstream infile("whereami.in");
    int line_num = 1;
    int n;
    int segment_size = 2;
    string street;
    string line;

    while (getline(infile, line)) {
        istringstream iss(line);
        if (line_num == 1) {
            iss >> n;
        }
        else {
            iss >> street;
        }
        line_num++;
    }

    for (int i = 2; i <= n; i++) {
        vector<string> prev_segments;
        bool solution = true;
        for (int j = 0; j < n - (segment_size - 1); j++) {
            string current_segment = street.substr(j, i);
            for (string segment : prev_segments) {
                if (current_segment == segment) {
                    solution = false;
                    break;
                }
            }
            if (!solution) {
                break;
            } else {
                prev_segments.push_back(current_segment);
            }
        }
        if (solution) {
            segment_size = i;
            break;
        }
    }

    ofstream outfile("whereami.out");
    outfile << segment_size;
    outfile.close();
}