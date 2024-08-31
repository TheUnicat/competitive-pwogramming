//
// Created by TheUnicat on 2024-05-25.
//

#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

int main() {
    std::ifstream infile("cownomics.in");
    int line_number = 1;
    std::string line;
    std::vector<std::vector<char> > spotted;
    std::vector<std::vector<char> > plain;
    int n;
    int m;
    int count = 0;

    while (getline(infile, line)) {
        if (line_number == 1) {
            std::istringstream iss(line);
            iss >> n >> m;
        } else if (line_number <= n + 1) {
            std::vector<char> temp;
            for (char character : line) {
                temp.push_back(character);
            }
            spotted.push_back(temp);
        } else {
            std::vector<char> temp;
            for (char character : line) {
                temp.push_back(character);
            }
            plain.push_back(temp);
        }


        line_number++;
    }
    infile.close();


    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                bool predictor = true;
                for (int ij = 0; ij < n; ij++) {
                    for (int ji = 0; ji < n; ji++) {
                        if (!((spotted[ij][i] != plain[ji][i]) || (spotted[ij][j] != plain[ji][j]) || (spotted[ij][k] != plain[ji][k]))) {
                            predictor = false;
                            break;
                        }
                    }
                    if (!predictor) {
                        break;
                    }
                }
                if (predictor) {
                    count++;
                }
            }
        }
    }

    std::ofstream outfile("cownomics.out");
    outfile << count;
    outfile.close();
}