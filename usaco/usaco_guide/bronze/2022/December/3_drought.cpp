//
// Created by TheUnicat on 2024-06-30.
//

#include <iostream>
#include <algorithm>
using namespace std;

int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int length;
        cin >> length;
        long long cows[length];
        for (int j = 0; j < length; j++) {
            long long cow;
            cin >> cow;
            cows[j] = cow;
        }

        long long min = *min_element(cows, cows + length);
        long long food = 0;
        while (true) {
            bool progress = false;
            bool done = true;
            bool minus = false;
            for (int j = 0; j < length - 1; j++) {
                if (cows[j] == min) {
                    continue;
                }
                else {
                    progress = true;
                    long long difference = cows[j] - min;
                    cows[j] = min;
                    cows[j + 1] -= difference;
                    food += difference * 2;
                    if (cows[j+1] < 0) {
                        food = -1;
                        done = true;
                        minus = true;
                        break;
                    }
                    if (cows[j + 1] < min) {
                        min = cows[j + 1];
                        if (min < 0) {
                            food = -1;
                            done = true;
                            break;
                        }
                        done = false;
                    }
                }
            }

            if (cows[length - 1] != min && !minus) {
                done = false;
            }

            if (progress == false && done == false) {
                cout << -1 << endl;
                break;
            }
            else if (progress == false) {
                cout << 0 << endl;
                break;
            }
            if (done) {
                cout << food << endl;
                break;
            }
        }
    }
}