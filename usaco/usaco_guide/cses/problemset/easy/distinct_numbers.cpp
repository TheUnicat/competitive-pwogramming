//
// Created by TheUnicat on 2024-06-09.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    int n;
    int distinct = 1;
    cin >> n;
    vector<int> numbers;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        numbers.push_back(num);
    }
    sort(numbers.begin(), numbers.end());
    for (int i = 1; i < n; i++) {
        if (numbers[i] != numbers[i - 1]) {
            distinct++;
        }
    }

    cout << distinct;
}