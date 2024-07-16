//
// Created by TheUnicat on 2024-07-15.
//

#include <iostream>
#include <vector>
using namespace std;

int n;

vector<long long> factor_into_twos(long long num) {
    long long current_two = 1;
    vector<long long> factors;
    while (current_two <= num) {
        current_two *= 2;
    }
    if (current_two > num) current_two /= 2;

    while (current_two > 0) {
        if (current_two <= num) {
            num -= current_two;
            factors.push_back(current_two);
        }
        current_two /= 2;
    }

    return factors;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long test;
        cin >> test;
        vector<long long> factors = factor_into_twos(test);
        if (factors.size() == 1) {
            cout << 1 << endl;
            cout << test << endl;
            continue;
        }
        vector<long long> answers;
        answers.push_back(test);
        for (int j = 0; j < factors.size(); j++) answers.push_back(test - factors[factors.size() - j - 1]);
        cout << answers.size() << endl;
        for (int j = 0; j < answers.size(); j++) cout << answers[answers.size() - j - 1] << " ";
        cout << endl;
    }
}