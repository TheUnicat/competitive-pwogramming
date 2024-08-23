//
// Created by TheUnicat on 2024-08-23.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> num_occurrence_count(1000001, 0);

int n;
int num;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        num_occurrence_count[num]++;
    }

    for (int i = 1000000; i > 0; i--) {
        int found_multiples = 0;
        for (int j = i; j <= 1000000; j += i) {
            found_multiples += num_occurrence_count[j];
            if (found_multiples > 1) {
                cout << i;
                return 0;
            }
        }
    }
}
