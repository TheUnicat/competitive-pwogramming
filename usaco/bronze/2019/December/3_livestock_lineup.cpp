//
// Created by TheUnicat on 2024-06-03.
//

#include <sstream>
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
vector<pair<string, string> > constraints;
vector<string> cows;

bool check_config(vector<string> config) {
    int constraints_satisfied = 0;
    for (int i = 0; i < 7; i++) {
        string cow_one = config[i];
        string cow_two = config[i + 1];
        pair<string, string> pair_one = make_pair(cow_one, cow_two);
        pair<string, string> pair_two = make_pair(cow_two, cow_one);
        for (pair<string, string> constraint : constraints) {
            if (pair_one == constraint || pair_two == constraint) {
                constraints_satisfied++;
            }
        }
    }

    if (constraints_satisfied >= n) {
        ofstream outfile("lineup.out");
        for (string cow : config) {
            outfile << cow << endl;
        }
        outfile.close();
        return true;
    }
    return false;
}

int main() {
    ifstream infile("lineup.in");
    int line_number = 1;
    string line;

    while (getline(infile, line)) {
        istringstream iss(line);
        if (line_number == 1) {
            iss >> n;
        }
        else {
            pair<string, string> current_constraint;
            int word = 1;
            string word_content;
            while (iss >> word_content) {
                if (word == 1) {
                    current_constraint.first = word_content;
                } else if (word == 6) {
                    current_constraint.second = word_content;
                }
                word++;
            }
            constraints.push_back(current_constraint);
        }
        line_number++;
    }
    infile.close();

    cows.push_back("Beatrice");
    cows.push_back("Blue");
    cows.push_back("Buttercup");
    cows.push_back("Sue");
    cows.push_back("Bessie");
    cows.push_back("Betsy");
    cows.push_back("Bella");
    cows.push_back("Belinda");

    sort(cows.begin(), cows.end());

    vector<string> cows_copy = cows;
    do {
        if (check_config(cows_copy)) {
            break;
        }
    } while (next_permutation(cows_copy.begin(), cows_copy.end()));
}