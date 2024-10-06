//
// Created by TheUnicat on 2024-10-05.
//

#include <iostream>
#include <vector>
using namespace std;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m, q;
        bool possible = true;
        cin >> n >> m >> q;
        vector<int> init_ord(n);
        vector<int> first_found(n, -1);
        for (int j = 0; j < n; j++) cin >> init_ord[j];
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;
            num--;
            if (first_found[num] == -1) first_found[num] = j;
        }

        int prev_pos = -1;
        for (int j = 0; j < n; j++) {
            if ((first_found[init_ord[j] - 1] < prev_pos) && (first_found[init_ord[j] - 1] != -1)) {
                possible = false;
                break;
            }
            prev_pos = first_found[init_ord[j]];
        }


        if (possible) cout << "YA" << endl;
        else cout << "TIDAK" << endl;
    }
}