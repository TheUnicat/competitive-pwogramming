//
// Created by TheUnicat on 2024-08-11.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> cow_teams;
int c, n;
string team;
vector<int> min_distances;

int inverse(int num) {
    int mask = (1 << c) - 1;

    return num ^ mask;
}

int main() {
    cin >> c >> n;
    min_distances.resize(1 << c, c + 1);
    for (int i = 0; i < n; i++) {
        int num = 0;
        cin >> team;
        for (int j = 1; j <= c; j++) {
            if (team[c - j] == 'H') num |= (1 << (c - j));
        }

        min_distances[num] = 0;
        cow_teams.push_back(num);
    }

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < 1 << c; j++) {
            if (min_distances[j] == c + 1) continue;
            min_distances[j ^ (1 << i)] = min(min_distances[j] + 1, min_distances[j ^ (1 << i)]);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << c - min_distances[inverse(cow_teams[i])] << endl;
    }
}