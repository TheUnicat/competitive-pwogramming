//
// Created by TheUnicat on 2024-05-11.
//
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <fstream>

int main() {
    std::ifstream infile("teleport.in");
    std::string input;
    std::getline(infile, input);
    std::istringstream iss(input);
    std::vector<int> parameters;

    int number; // temporary storage

    while (iss >> number) {
        parameters.push_back(number);
    }

    int x_coord = parameters[0];
    int y_coord = parameters[1];

    int teleportation_x = parameters[2];
    int teleportation_y = parameters[3];

    if (teleportation_y < teleportation_x) {
        int temp_storage = teleportation_x;
        teleportation_x = teleportation_y;
        teleportation_y = temp_storage;
    }

    if (y_coord < x_coord) {
        int temp_storage = x_coord;
        x_coord = y_coord;
        y_coord = temp_storage;
    }

    int raw_distance = y_coord - x_coord;

    int teledistance = abs(teleportation_x - x_coord) + abs(teleportation_y - y_coord);

    int min_distance = raw_distance > teledistance ? teledistance : raw_distance;

    std::ofstream outfile("teleport.out");
    outfile << min_distance << std::endl;
    outfile.close();

    return 0;
}