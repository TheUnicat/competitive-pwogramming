//
// Created by TheUnicat on 2024-06-13.
//

#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ifstream infile("notlast.in");
    int line_num = 1;
    string line;
    int n;
    vector<pair<int, string> > milking;
    milking.push_back(make_pair(0, "Annabelle"));
    milking.push_back(make_pair(0, "Elsie"));
    milking.push_back(make_pair(0, "Daisy"));
    milking.push_back(make_pair(0, "Gertie"));
    milking.push_back(make_pair(0, "Bessie"));
    milking.push_back(make_pair(0, "Maggie"));
    milking.push_back(make_pair(0, "Henrietta"));

    while (getline(infile, line)) {
        istringstream iss(line);
        if (line_num == 1) {
            iss >> n;
        }
        else {
            string cow;
            int milk;
            iss >> cow >> milk;
            for (int i = 0; i < milking.size(); i++) {
                auto info = milking[i];
                if (info.second == cow) {
                    milking[i].first += milk;
                    break;
                }
            }
        }
        line_num++;
    }

    sort(milking.begin(), milking.end());
    int min = milking[0].first;

    for (int i = 1; i < 7; i++) {
        if (milking[i].first > min) {
            if (i == 6 || milking[i + i].first > milking[i].first) {
                ofstream outfile("notlast.out");
                outfile << milking[i].second;
                outfile.close();
                break;
            } else {
                ofstream outfile("notlast.out");
                outfile << "Tie";
                outfile.close();
                break;
            }
        }
    }
}