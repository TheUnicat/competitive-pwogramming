//
// Created by TheUnicat on 2024-09-21.
//

#include <iostream>
using namespace std;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int curr_gold = 0;
        int n_given = 0;
        int n, threshold;
        cin >> n >> threshold;

        for (int j = 0; j < n; j++) {
            int person_gold;
            cin >> person_gold;
            if (person_gold >= threshold) curr_gold += person_gold;
            else if (person_gold == 0) {
                if (curr_gold > 0) {
                    curr_gold--;
                    n_given++;
                }
            }
        }

        cout << n_given << endl;
    }
}