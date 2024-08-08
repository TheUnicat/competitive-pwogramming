//
// Created by TheUnicat on 2024-08-07.
//

#include <iostream>
#include <string>
#include <queue>
using namespace std;

string test;
int t;
int n;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        cin >> test;
        int open_n = 0;
        int open_sum = 0;
        int closed_sum = 0;

        for (int j = 0; j < n; j++) {
            if (test[j] == '(') {
                open_n++;
                open_sum += j;
            }
            else if (test[j] == ')') {
                open_n--;
                closed_sum += j;
            }
            else {
                if (open_n > 0) {
                    open_n--;
                    closed_sum += j;
                }
                else {
                    open_n++;
                    open_sum += j;
                }
            }
        }

        cout << closed_sum - open_sum << endl;
    }
}