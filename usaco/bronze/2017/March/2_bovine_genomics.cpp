//
// Created by TheUnicat on 2024-05-23.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream infile("cownomics.in");
    int line = 1;
    int n;
    int m;
    std::vector<std::vector<char> > cows;
    std::string line_content;

    while (std::getline(infile, line_content)) {
        std::istringstream iss(line_content);
        if (line == 1) {
            iss >> n >> m;
        } else {
            std::vector<char> temp;
            for (char character : line_content) {
                temp.push_back(character);
            }

            cows.push_back(temp);
        }
        line++;
    }
    infile.close();

    int count = 0;

    for (int i = 0; i < m; i++) {
        bool can_add = true;
        std::vector<char> spotted_chars;
        for (int j = 0; j < (2 * n); j++) {
            char character = cows[j][i];
            if (j < n) {
                spotted_chars.push_back(character);
            } else {
                if (std::find(spotted_chars.begin(), spotted_chars.end(), character) != spotted_chars.end()) {
                    can_add = false;
                }
            }
        }

        if (can_add) {
            count++;
        }
    }

    std::ofstream outfile("cownomics.out");
    outfile << count;
}
