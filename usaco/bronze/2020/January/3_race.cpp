//
// Created by TheUnicat on 2024-06-24.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;

int n, k;
vector<int> test_cases;

bool is_speed_ok(int speed, int length_remaining, int speed_limit) {
    if (speed <= speed_limit) {
        return true;
    }
    if ((speed + speed_limit)*0.5*(speed - speed_limit + 1) - speed_limit < length_remaining) {
        return true;
    }
    return false;
}

int main() {
    ifstream infile("race.in");
    string line;
    getline(infile, line);
    istringstream iss(line);
    iss >> k >> n;
    for (int i = 0; i < n; i++) {
        getline(infile, line);
        int num = stoi(line);
        test_cases.push_back(num);
    }


    ofstream outfile("race.out");
    for (int test_case : test_cases) {
        int time = 0;
        int speed = 0;
        int distance = 0;
        while (distance < k) {
            if (is_speed_ok(speed + 1, k - distance, test_case)) {
                speed++;
            }
            else if (is_speed_ok(speed, k - distance, test_case)) {}
            else {
                speed--;
            }
            distance += speed;
            time++;
        }

        outfile << time << endl;
    }

    outfile.close();
}
