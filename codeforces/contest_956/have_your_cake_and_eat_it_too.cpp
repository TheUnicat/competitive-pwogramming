//
// Created by TheUnicat on 2024-07-07.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int size;
        int total_reward = 0;
        int min_reward;
        cin >> size;
        int values [3][size];
        for (int j = 0; j < size; j++) {
            cin >> values[0][j];
            total_reward += values[0][j];
        }
        min_reward = total_reward/3;
        if (total_reward % min_reward != 0) {
            min_reward++;
        }
        for (int j = 0; j < size; j++) {
            cin >> values[1][j];
        }
        for (int j = 0; j < size; j++) {
            cin >> values[2][j];
        }

        vector<int> one_two_three;
        one_two_three.push_back(0);
        one_two_three.push_back(1);
        one_two_three.push_back(2);

        bool solved = false;
        do {
            pair<int, int> people[3];
            int current_index = -1;
            bool done = false;
            for (int m = 0; m < 3; m++) {
                current_index++;
                if (current_index == size) break;
                int start_index = current_index;
                int person = one_two_three[m];
                int current_reward = 0;
                while (true) {
                    current_reward += values[person][current_index];
                    if (current_reward >= min_reward) {
                        people[person].first = start_index;
                        people[person].second = current_index;
                        if (m == 2) {
                            done = true;
                        }
                        break;
                    }
                    if (current_index < size - 1) {
                        current_index++;
                    } else {
                        break;
                    }
                }

            }
            if (done == true) {
                solved = true;
                for (auto pos : people) {
                    cout << pos.first + 1 << " " << pos.second + 1 << " ";
                }
                cout << endl;
                break;
            }


        } while (next_permutation(one_two_three.begin(), one_two_three.end()));
        if (!solved) {
            cout << -1 << endl;
        }
    }
}

