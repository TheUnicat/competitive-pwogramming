//
// Created by TheUnicat on 2024-05-12.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    int one_capacity, two_capacity, three_capacity;
    int one_vol, two_vol, three_vol;
    std::string line;
    std::ifstream infile("mixmilk.in");
    int line_count = 1;

    while (std::getline(infile, line)) {
        int number;
        std::istringstream iss(line);
        int capacity = 0;
        while (iss >> number) {
            switch (line_count) {
                case 1:
                    if (capacity == 0) {
                        one_capacity = number;
                    } else {
                        one_vol = number;
                    }
                case 2:
                    if (capacity == 0) {
                        two_capacity = number;
                    } else {
                        two_vol = number;
                    }
                case 3:
                    if (capacity == 0) {
                        three_capacity = number;
                    } else {
                        three_vol = number;
                    }
            }
            capacity++;
        }
        line_count++;
    }


    for (int i = 0; i < 100; i++) {
        if (i % 3 == 0) {
            int moved = one_vol;
            int temp = one_vol + two_vol;
            if (temp > two_capacity) {
                moved = two_capacity - two_vol;
            }

            two_vol += moved;
            one_vol = one_vol - moved;
        } else if (i % 3 == 1) {

            int moved = two_vol;
            int temp = two_vol + three_vol;
            if (temp > three_capacity) {
                moved = three_capacity - three_vol;
            }


            three_vol += moved;
            two_vol = two_vol - moved;

        } else {
            int moved = three_vol;
            int temp = three_vol + one_vol;
            if (temp > one_capacity) {
                moved = one_capacity - one_vol;
            }

            one_vol += moved;
            three_vol = three_vol - moved;
        }
    }

    std::ofstream outfile("mixmilk.out");
    outfile << one_vol << "\n" << two_vol << "\n" << three_vol;
    outfile.close();
}