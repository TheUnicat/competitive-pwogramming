//
// Created by TheUnicat on 2024-06-29.
//

#include <fstream>
#include <sstream>
using namespace std;

int main() {
    ifstream infile("paint.in");
    string line;
    int a, b, c, d;

    getline(infile, line);
    istringstream iss(line);
    iss >> a >> b;
    getline(infile, line);
    istringstream iss_two(line);
    iss_two >> c >> d;
    infile.close();

    int distance = ((d >= a && b >= c) || (c >= b && a >=d)) ? max(b, d) - min(a, c) : b - a + d - c;
    ofstream outfile("paint.out");
    outfile << distance;
    outfile.close();
}