//
// Created by TheUnicat on 2024-05-21.
//

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main() {
    std::string n_lines_temp;
    std::string temp_x;
    std::string temp_y;
    std::vector<int> x_values;
    std::vector<int> y_values;

    std::getline(std::cin, n_lines_temp);
    int n_lines = std::stoi(n_lines_temp);
    std::getline(std::cin, temp_x);
    std::getline(std::cin, temp_y);

    std::istringstream iss(temp_x);
    int number;

    while (iss >> number) {
        x_values.push_back(number);
    }

    std::istringstream iss_2(temp_y);
    while (iss_2 >> number) {
        y_values.push_back(number);
    }

    int max_distance = 0;

    for (int i = 0; i < n_lines; i++) {
        int x_value = x_values[i];
        int y_value = y_values[i];

        for (int j = i + 1; j < n_lines; j++) {
            int x_2 = x_values[j];
            int y_2 = y_values[j];
            int x_distance = x_2 - x_value;
            x_distance = x_distance * x_distance;
            int y_distance = y_2 - y_value;
            y_distance = y_distance * y_distance;

            int final_distance = y_distance + x_distance;

            if (final_distance > max_distance) {
                max_distance = final_distance;
            }

        }
    }

    std::cout << max_distance << std::endl;
}
