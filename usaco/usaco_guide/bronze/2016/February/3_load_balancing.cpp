//
// Created by TheUnicat
//

#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int compute_max(int x_position, int y_position, std::vector<std::pair<int, int> > positions, std::vector<std::pair<int, int> > positions_reversed) {

    int q1 = 0;
    int q2 = 0;
    int q3 = 0;
    int q4 = 0;

    for (std::pair<int, int> coords : positions) {
        if (coords.first > x_position && coords.second > y_position) {
            q1++;
        } else if (coords.first < x_position && coords.second > y_position) {
            q2++;
        } else if (coords.first < x_position && coords.second < y_position) {
            q3++;
        } else {
            q4++;
        }
    }

    int max = std::max(q1, q2);
    int max_2 = std::max(q3, q4);
    max = std::max(max, max_2);
    return max;
}

int main() {
    std::ifstream infile("balancing.in");
    int line_number = 1;
    std::string line;
    int N;
    int B;
    std::vector<std::pair<int, int> > positions;
    std::vector<std::pair <int, int> > positions_reversed;

    while(getline(infile, line)) {
        std::istringstream iss(line);
        if (line_number == 1) {
            iss >> N >> B;
        } else {
            int x;
            int y;
            iss >> x >> y;
            positions.push_back(std::make_pair(x, y));
            positions_reversed.push_back(std::make_pair(y, x));
        }
        line_number++;
    }
    infile.close();

    std::sort(positions.begin(), positions.end());
    std::sort(positions_reversed.begin(), positions_reversed.end());

    int min = 1000;

    for (std::pair<int, int> first_pair : positions) {
        int i = first_pair.first + 1;
        for (std::pair<int, int> second_pair : positions_reversed) {
            int j = second_pair.first + 1;
            int max = compute_max(i, j, positions, positions_reversed);
            if (max < min) {
                min = max;
            }
        }
    }

    std::ofstream outfile("balancing.out");
    outfile << min;
    outfile.close();
}