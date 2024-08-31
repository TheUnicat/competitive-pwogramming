//
// Created by TheUnicat on 2024-05-27.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int m;
int min_cost = 10000;
vector<vector<int> > cows;
vector<int> coolings(100, 0);
vector<vector<int> > acs;


void test_configuration(vector<int> selected) {
    int total_cost = 0;
    vector<int> copy_coolings = coolings;
    for (int number : selected) {
        vector<int> ac = acs[number];

        for (int i = ac[0]; i < ac[1] + 1; i++) {
            copy_coolings[i - 1] += ac[2] * -1;
        }

        total_cost += ac[3];
    }

    for (int temperature : copy_coolings) {
        if (temperature > 0) {
            return;
        }
    }

    if (total_cost < min_cost) {
        min_cost = total_cost;
    }
}

void find_combinations(int starting_index, int m, vector<int> current) {

    vector<int> current_permutation(m, 0);

    for (int i = 0; i < m; i++) {
        current_permutation[i] = i;
    }

    test_configuration(current);

    for (int i = starting_index; i < m; i++) {
        current.push_back(current_permutation[i]);
        find_combinations(i + 1, m, current);
        current.pop_back();
    }
}

int main() {
    cin >> n;
    cin >> m;


    for (int i = 0; i < n; i++) {
        vector<int> temp;
        int number;
        for (int i = 0; i < 3; i++) {
            cin >> number;
            temp.push_back(number);
        }
        cows.push_back(temp);
    }

    for (vector<int> cow : cows) {
        for (int i = cow[0] - 1; i < cow[1]; i++) {
            coolings[i] = cow[2];
        }
    }

    for (int i = 0; i < m; i++) {
        vector<int> temp;
        int number;
        for (int j = 0; j < 4; j++) {
            cin >> number;
            temp.push_back(number);
        }
        acs.push_back(temp);
    }

    vector<int> empty;

    find_combinations(0, m, empty);


    cout << min_cost;
}