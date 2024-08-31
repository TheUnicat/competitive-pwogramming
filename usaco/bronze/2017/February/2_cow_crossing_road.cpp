//
// Created by TheUnicat on 2024-05-25.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream infile("circlecross.in");
    std::string farm;
    infile >> farm;
    int count = 0;
    std::vector<std::pair<char, char> > pairs;
    std::string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (char character : letters) {
        int point_one = 0;
        int point_two = 0;
        for (int i = 1; i <= 52; i++) {
            char letter = farm[i - 1];
            if (letter == character) {
                if (point_one == 0) {
                    point_one = i - 1;
                } else {
                    point_two = i - 1;
                    break;
                }
            }
        }

        std::vector<char> enclosed_letters;

        for (int i = point_one + 1; i < point_two; i++) {
            auto index = std::find(enclosed_letters.begin(), enclosed_letters.end(), farm[i]);
            if (index != enclosed_letters.end()) {
                enclosed_letters.erase(enclosed_letters.begin() + int(std::distance(enclosed_letters.begin(), index)));
            } else {
                enclosed_letters.push_back(farm[i]);
            }
        }

        for (char letter : enclosed_letters) {
            if (std::find(pairs.begin(), pairs.end(), std::make_pair(letter, character)) == pairs.end()) {
                count++;
                pairs.push_back(std::make_pair(character, letter));
            }
        }

        std::ofstream outfile("circlecross.out");
        outfile << count;
        outfile.close();
    }
}