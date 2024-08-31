//
// Created by TheUnicat on 2024-05-12.
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

int main () {
    std::ifstream infile("buckets.in");
    std::string file_line;

    int barn_x, barn_y;
    int rock_x, rock_y;
    int lake_x, lake_y;

    int current_line = 1;

    while (std::getline(infile, file_line)) {

        int current_char = 1;

        for (char chawacter : file_line) {
            if (chawacter == 'B') {
                barn_x = current_line;
                barn_y = current_char;
            }
            else if (chawacter == 'L') {
                lake_x = current_line;
                lake_y = current_char;
            }
            else if (chawacter == 'R') {
                rock_x = current_line;
                rock_y = current_char;
            }

            current_char++;
        }

        current_line++;
    }

    infile.close();

    int orig_distance = abs(barn_x - lake_x) + abs(barn_y - lake_y) - 1;

    if (rock_x == barn_x && barn_x == lake_x) {
        if (rock_y > barn_y && rock_y < lake_y) {
            orig_distance += 2;
        }
        else if (rock_y < barn_y && rock_y > lake_y) {
            orig_distance += 2;
        }
    } else if (rock_y == barn_y && barn_y == lake_y) {
        if (rock_x > barn_x && rock_x < lake_x) {
            orig_distance += 2;
        }
        else if (rock_x < barn_x && rock_x > lake_x) {
            orig_distance += 2;
        }
    }

    std::ofstream outfile("buckets.out");

    outfile << orig_distance;
    outfile.close();
}