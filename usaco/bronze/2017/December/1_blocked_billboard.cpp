//
// Created by TheUnicat on 2024-06-29.
//

#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int one_bottom_x, one_bottom_y, one_top_x, one_top_y;
int two_bottom_x, two_bottom_y, two_top_x, two_top_y;
int steak_bottom_x, steak_bottom_y, steak_top_x, steak_top_y;

int main() {
    ifstream infile("billboard.in");
    string line;
    getline(infile, line);
    istringstream iss(line);
    iss >> one_bottom_x >> one_bottom_y >> one_top_x >> one_top_y;
    getline(infile, line);
    istringstream iss_two(line);
    iss_two >> two_bottom_x >> two_bottom_y >> two_top_x >> two_top_y;
    getline(infile, line);
    istringstream iss_three(line);
    iss_three >> steak_bottom_x >> steak_bottom_y >> steak_top_x >> steak_top_y;
    infile.close();

    int total_area = (one_top_x - one_bottom_x) * (one_top_y - one_bottom_y) + (two_top_x - two_bottom_x) * (two_top_y - two_bottom_y);
    total_area -= (max((min(one_top_x, steak_top_x) - max(one_bottom_x, steak_bottom_x)),0)) * (max((min(one_top_y, steak_top_y) - max(one_bottom_y, steak_bottom_y)),0));
    total_area -= (max((min(two_top_x, steak_top_x) - max(two_bottom_x, steak_bottom_x)),0)) * (max((min(two_top_y, steak_top_y) - max(two_bottom_y, steak_bottom_y)),0));

    ofstream outfile("billboard.out");
    outfile << total_area;
    outfile.close();
}