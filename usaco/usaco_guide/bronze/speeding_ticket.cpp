//
// Created by TheUnicat on 2024-05-13.
//
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

int main() {
    std::ifstream infile("speeding.in");
    int line_number = 1;
    int n_signs;
    int n_speed_changes;
    std::vector<int> speed_limits;
    std::vector<int> bessie_speeds;
    std::string line;

    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        if (line_number == 1) {
            iss >> n_signs >> n_speed_changes;
        } else if (line_number - 1 <= n_signs) {
            int length, speed;
            iss >> length >> speed;
            for (int i = 0; i < length; i++) {
                speed_limits.push_back(speed);
            }
        } else if (line_number - 1 - n_signs <= n_speed_changes) {
            int length, speed;
            iss >> length >> speed;
            for (int i = 0; i < length; i++) {
                bessie_speeds.push_back(speed);
            }
        }
        line_number++;
    }
    infile.close();

    int max_speeding = 0;

    for (int i = 0; i < 100; i++) {
        if (bessie_speeds[i] - speed_limits[i] > max_speeding) {
            max_speeding = bessie_speeds[i] - speed_limits[i];
        }
    }

    std::ofstream outfile("speeding.out");
    outfile << max_speeding;
    outfile.close();
}