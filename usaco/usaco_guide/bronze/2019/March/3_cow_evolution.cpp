//
// Created by TheUnicat on 2024-06-29.
//

//telepathic
//telepathic spots
//spots

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int n;
vector<vector<string> > cows;
set<string> traits;

int main() {
    ifstream infile("evolution.in");
    string line;
    getline(infile, line);
    n = stoi(line);
    for (int i = 0; i < n; i++) {
        getline(infile, line);
        istringstream iss(line);
        int size;
        iss >> size;
        vector<string> cow_info;
        for (int j = 0; j < size; j++) {
            string trait;
            iss >> trait;
            traits.insert(trait);
            cow_info.push_back(trait);
        }
        cows.push_back(cow_info);
    }
    infile.close();

    ofstream outfile("evolution.out");
    for (int i = 0; i < traits.size(); i++) {
        for (int j = i+1; j < traits.size(); j++) {
            auto it = traits.begin();
            advance(it, i);
            string trait = *it;
            it = traits.begin();
            advance(it, j);
            string trait_two = *it;
            bool trait_one_alone = false;
            bool trait_two_alone = false;
            bool both_traits = false;

            for (vector<string> cow_info : cows) {
                bool is_one = find(cow_info.begin(), cow_info.end(), trait) != cow_info.end();
                bool is_two = find(cow_info.begin(), cow_info.end(), trait_two) != cow_info.end();
                if (is_one == true && is_two == true) {
                    both_traits = true;
                }
                else if (is_one == true) {
                    trait_one_alone = true;
                }
                else if (is_two == true) {
                    trait_two_alone = true;
                }
            }

            if (trait_one_alone == true && trait_two_alone == true && both_traits == true) {
                outfile << "no";
                outfile.close();
                return 0;
            }
        }
    }
    outfile << "yes";
    outfile.close();
    return 0;
}