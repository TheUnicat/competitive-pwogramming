#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_good_final(const vector<pair<int, int> >& current_state, const vector<int>& final_state) {
    for (int i = 0; i < final_state.size(); i++) {
        if (current_state[i].first != final_state[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream infile("tracing.in");
    int n_cows;
    int n_records;
    vector<int> cows;
    vector<pair<int, pair<int, int> > > records;
    string line_content;
    int line_number = 1;

    while (getline(infile, line_content)) {
        istringstream iss(line_content);
        if (line_number == 1) {
            iss >> n_cows >> n_records;
        } else if (line_number == 2) {
            for (char character : line_content) {
                cows.push_back(character - '0');
            }
        } else {
            int time, cow_one, cow_two;
            iss >> time >> cow_one >> cow_two;
            records.push_back(std::make_pair(time, std::make_pair(cow_one, cow_two)));
        }
        line_number++;
    }
    infile.close();

    sort(records.begin(), records.end());
    int possible_cows = 0;
    int k_min = n_records;
    int k_max = 0;

    for (int i = 1; i <= n_cows; i++) {
        bool is_possible = false;
        for (int j = 0; j <= n_records; j++) {
            vector<pair<int, int> > temp_farm(n_cows, std::make_pair(0, 0));
            temp_farm[i - 1].first = 1;

            for (const auto& record : records) {
                int cow_one = record.second.first - 1;
                int cow_two = record.second.second - 1;
                if (temp_farm[cow_one].first == 1 && temp_farm[cow_two].first == 1) {
                    temp_farm[cow_one].second++;
                    temp_farm[cow_two].second++;
                }
                else if (temp_farm[cow_one].first == 1 && temp_farm[cow_one].second < j) {
                    temp_farm[cow_two].first = 1;
                    temp_farm[cow_one].second++;
                } else if (temp_farm[cow_two].first == 1 && temp_farm[cow_two].second < j) {
                    temp_farm[cow_one].first = 1;
                    temp_farm[cow_two].second++;
                }
            }

            if (is_good_final(temp_farm, cows)) {
                is_possible = true;
                k_min = min(k_min, j);
                k_max = max(k_max, j);
            }
        }

        if (is_possible) {
            possible_cows++;
        }
    }

    string final_k_max = k_max == n_records ? "Infinity" : to_string(k_max);
    ofstream outfile("tracing.out");
    outfile << possible_cows << " " << k_min << " " << final_k_max;
    outfile.close();

    return 0;
}
