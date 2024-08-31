//
// Created by TheUnicat on 2024-06-29.
//

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

int x_one_bottom, x_one_top, y_one_bottom, y_one_top;
int x_two_bottom, x_two_top, y_two_bottom, y_two_top;

int main() {
    ifstream infile("billboard.in");
    string line;
    getline(infile, line);
    istringstream iss(line);
    iss >> x_one_bottom >> y_one_bottom >> x_one_top >> y_one_top;
    getline(infile, line);
    istringstream iss_two(line);
    iss_two >> x_two_bottom >> y_two_bottom >> x_two_top >> y_two_top;

    int x = x_one_top - x_one_bottom;
    int y = y_one_top - y_one_bottom;
    int area = x * y;
    int x_overlap = max(0, min(x_one_top, x_two_top) - max(x_one_bottom, x_two_bottom));
    int y_overlap = max(0, min(y_one_top, y_two_top) - max(y_one_bottom, y_two_bottom));

    if (x_overlap < x && y_overlap < y) {}
    else if (x_overlap >= x && y_overlap >= y) {
        area = 0;
    }
    else if (x_overlap >= x) {
        if ((y_two_bottom <= y_one_bottom && y_two_top >= y_one_bottom) || (y_two_bottom > y_one_bottom && y_two_top >= y_one_top)) {
            area -= x * y_overlap;
        }
    }
    else {
        if ((x_two_bottom <= x_one_bottom && x_two_top >= x_one_bottom) || (x_two_bottom > x_one_bottom && x_two_top >= x_one_top)) {
            area -= y * x_overlap;
        }
    }

    ofstream outfile("billboard.out");
    outfile << area;
    outfile.close();
}
