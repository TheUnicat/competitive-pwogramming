//
// Created by TheUnicat on 2024-08-11.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;
using ll = long long;

map<int, ll> combinations;
string test;
ll total_combinations = 0;

int main() {
    cin >> test;
    int num = 0;
    combinations[num]++;
    for (int i = 0; i < test.length(); i++) {
        num ^= 1 << (test[i] - '0');
        combinations[num]++;
    }

    for (const auto&[key, value] : combinations) {
        total_combinations += (value * (value - 1)) / 2;
    }

    cout << total_combinations;
}