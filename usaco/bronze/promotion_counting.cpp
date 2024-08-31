//
// Created by TheUnicat on 2024-05-12.
//
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    int prev_bronze;
    int new_bronze;
    int prev_silver;
    int new_silver;
    int prev_gold;
    int new_gold;
    int prev_plat;
    int new_plat;

    int line_number = 1;

    std::ifstream infile("promote.in");

    std::string line;

    while (getline(infile, line)) {
        std::istringstream stringy_mcstringface(line);
        switch (line_number) {
            case 1:
                stringy_mcstringface >> prev_bronze >> new_bronze;
            case 2:
                stringy_mcstringface >> prev_silver >> new_silver;
            case 3:
                stringy_mcstringface >> prev_gold >> new_gold;
            case 4:
                stringy_mcstringface >> prev_plat >> new_plat;
        }

        line_number++;
    }

    infile.close();

    int to_silver;
    int to_gold;
    int to_plat;

    to_plat = new_plat - prev_plat;
    new_gold += to_plat;

    to_gold = new_gold - prev_gold;
    new_silver += to_gold;

    to_silver = new_silver - prev_silver;

    std::ofstream outfile("promote.out");
    outfile << to_silver << "\n" << to_gold << "\n" << to_plat;
    outfile.close();
}