//
// Created by TheUnicat on 2024-07-11.
//

#include <iostream>
#include <string>
using namespace std;

int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int n, m, k;
        string input;
        cin >> n >> m >> k;
        cin >> input;
        string test = 'L' + input + 'L';

        int water_traveled = 0;
        bool pass = true;
        int j = 0;
        while (true) {
            if (j == n + 1) break;
            char object = test[j];
            //cout << j << " " << object << " ";
            if (object == 'L') {
                bool found_water = false;
                bool found_log = false;
                int max_index;
                for (int p = j + 1; p <= min(j + m, n + 1); p++) {
                    //cout << " test " << test[p] << endl;
                    if (!found_water && (test[p] == 'W' || test[p] == 'L')) {
                        if (test[p] == 'W') {
                            found_water = true;
                        } else {
                            found_log = true;
                            found_water = true;
                        }
                        max_index = p;
                    }
                    else if (test[p] == 'L') {
                        max_index = p;
                        found_log = true;
                    }
                    else if (!found_log && test[p] == 'W') {
                        max_index = p;
                    }
                }
                //cout << " result " << max_index << " ";
                if (!found_water) {
                    pass = false;
                    break;
                }
                else {
                    j = max_index;
                    continue;
                }
            }
            else if (object == 'C') {
                pass = false;
                break;
            }
            else if (object == 'W') {
                water_traveled++;
                if (water_traveled > k) {
                    pass = false;
                    break;
                }
                j++;
            }
        }
        if (pass) cout << "YES" << endl; else cout << "NO" << endl;
    }
}
