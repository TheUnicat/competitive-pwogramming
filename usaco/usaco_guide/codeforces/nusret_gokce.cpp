//
// Created by TheUnicat on 2024-07-07.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    vector<int> salt_grains(n);
    for (int i = 0; i < n; i++) {
        cin >> salt_grains[i];
    }

    bool done = false;
    while (done == false) {
        done = true;
        for (int i = 0; i < n - 1; i++) {
            if (salt_grains[i] - salt_grains[i + 1] > m) {
                salt_grains[i + 1] += salt_grains[i] - salt_grains[i + 1]  - m;
                done = false;
            }
        }

        for (int i = n - 1; i > 0; i--) {
            if (salt_grains[i] - salt_grains[i - 1] > m) {
                salt_grains[i - 1] += salt_grains[i] - salt_grains[i - 1]  - m;
                done = false;
            }
        }
    }

    for (int grain : salt_grains) {
        cout << grain << " ";
    }
}
