//
// Created by TheUnicat on 2024-05-12.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

int main() {
    std::ifstream infile("shell.in");
    int n_swaps;
    std::string line;
    int current_line = 1;
    std::vector<std::vector<int> > game_history;

    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        if (current_line == 1) {
            iss >> n_swaps;
        } else {
            std::vector<int> temp_vector;

            int cowteger;
            while (iss >> cowteger) {
                temp_vector.push_back(cowteger);
            }
            game_history.push_back(temp_vector);
        }

        current_line++;
    }

    infile.close();

    int one_wins, two_wins, three_wins = 0;

    for (int i = 1; i <= 3; i++) {
        std::vector<int> current_game;
        current_game.push_back(1);
        current_game.push_back(2);
        current_game.push_back(3);

        for (std::vector<int> round : game_history) {
            int swap_index = round[0];
            int swap_index_two = round[1];
            int guess_index = round[2];

            std::vector<int> copy_game = current_game;
            current_game[swap_index - 1] = copy_game[swap_index_two - 1];
            current_game[swap_index_two - 1] = copy_game[swap_index - 1];
            if (current_game[guess_index - 1] == i) {
                if (i == 1) {
                    one_wins++;
                }
                else if (i == 2) {
                    two_wins++;
                }
                else {
                    three_wins++;
                }
            }
        }
    }

    int max_score = one_wins;
    if (two_wins > max_score) {
        max_score = two_wins;
    }

    if (three_wins > max_score) {
        max_score = three_wins;
    }

    std::ofstream outfile("shell.out");
    outfile << max_score;
    outfile.close();
}