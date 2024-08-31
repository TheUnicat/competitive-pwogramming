//
// Created by TheUnicat on 2024-05-13.
//

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream infile("blocks.in");
    std::string line;
    int line_number = 1;
    int n_cards;
    std::vector<std::vector<std::string> > boxes;

    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        if (line_number == 1) {
            iss >> n_cards;
        } else {
            std::string word_one, word_two;
            iss >> word_one >> word_two;
            std::vector<std::string> temp_vector;
            temp_vector.push_back(word_one);
            temp_vector.push_back(word_two);
            boxes.push_back(temp_vector);
        }
        line_number++;
    }

    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::vector<int> count;

    for (char c : alphabet) {
        std::vector<std::string> temp_vector;
        temp_vector.push_back(std::to_string(c));
        int c_needed = 0;

        for (std::vector<std::string> subvector : boxes) {
            std::string word_one = subvector[0];
            std::string word_two = subvector[1];
            int letter_count_in_word_one = 0;
            int word_two_count = 0;
            for (char character : word_one) {
                if (character == c) {
                    letter_count_in_word_one++;
                }
            }
            for (char character : word_two) {
                if (character == c) {
                    word_two_count++;
                }
            }

            int max_score = letter_count_in_word_one;
            if (word_two_count > letter_count_in_word_one) {
                max_score = word_two_count;
            }

            c_needed += max_score;
        }

        temp_vector.push_back(std::to_string(c_needed));
        count.push_back(c_needed);
    }

    std::ofstream outfile("blocks.out");

    for (int integer : count) {
        outfile << integer << "\n";
    }

    outfile.close();
}