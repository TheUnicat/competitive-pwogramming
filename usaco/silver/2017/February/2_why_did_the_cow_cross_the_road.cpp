//
// Created by TheUnicat on 2024-06-30.
//

#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, b;

int main() {
    ifstream infile("maxcross.in");
    string line;
    getline(infile, line);
    istringstream iss(line);
    iss >> n >> k >> b;

    vector<int> broken;
    for (int i = 0; i < b; i++) {
        getline(infile, line);
        broken.push_back(stoi(line) - 1);
    }
    infile.close();
    sort(broken.begin(), broken.end());

    vector<int> prefix_sums;
    prefix_sums.push_back(0);
    int current_index = 0;
    int sum = 0;

    for (int index : broken) {
        sum += index - current_index;
        current_index = index;
        prefix_sums.push_back(sum);
    }
    prefix_sums.push_back(n);

    int min_lights = b;
    bool modified = false;
    for (int i = 0; i < prefix_sums.size(); i++) {
        int current_lights = prefix_sums[i];
        int n_fixed = -1;
        for (int j = i + 1; j < prefix_sums.size(); j++) {
            if (prefix_sums[j] - current_lights >= k) {
                n_fixed = j - i;
                break;
            }
        }

        if (n_fixed != -1 && n_fixed <= min_lights) {
            min_lights = n_fixed;
            modified = true;
        }
    }

    ofstream outfile("maxcross.out");
    if (modified) {
        min_lights--;
    }
    outfile << max(0, min_lights);
    outfile.close();
}

