//
// Created by Hong Yang on 2024-08-12.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int t, n;
vector<bool> primes(5000001, true);
int max_prime[4];
vector<int> turns_to_finish(5000001);


void populate_primes() {
    max_prime[0] = 2;
    max_prime[1] = 1;
    max_prime[2] = 2;
    max_prime[3] = 3;
    primes[1] = false;
    for (int i = 2; i <= 5000000; i++) {
        if (!primes[i]) {
            turns_to_finish[i] = (i - max_prime[i % 4]) / 2 + 1;
            continue;
        }

        for (int j = i * 2; j <= 5000000; j += i) {
            primes[j] = false;
        }
        if (i != 2) {
            max_prime[i % 4] = i;
        }
        turns_to_finish[i] = 1;
    }
}


int main() {
    populate_primes();
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<int> test_case(n);
        for (int j = 0; j < n; j++) cin >> test_case[j];

        int least_john_loss = 5000001;
        int least_nhoj_loss = 5000001;
        int john_loss_pos = n + 1;
        int nhoj_loss_pos = n + 1;

        for (int j = 0; j < n; j++) {
            if (test_case[j] % 4 == 0) {
                if (turns_to_finish[test_case[j]] / 2 + 1 < least_john_loss) {
                    least_john_loss = turns_to_finish[test_case[j]] / 2 + 1;
                    john_loss_pos = j;
                }
            }
            else {
                if (turns_to_finish[test_case[j]] / 2 + 1 < least_nhoj_loss) {
                    least_nhoj_loss = turns_to_finish[test_case[j]] / 2 + 1;
                    nhoj_loss_pos = j;
                }
            }
        }
        if (least_john_loss != least_nhoj_loss) {
            if (least_john_loss < least_nhoj_loss) {
                cout << "Farmer Nhoj" << endl;
            }
            else cout << "Farmer John" << endl;
        }
        else {
            if (nhoj_loss_pos < john_loss_pos) cout << "Farmer John" << endl;
            else cout << "Farmer Nhoj" << endl;
        }
    }
}