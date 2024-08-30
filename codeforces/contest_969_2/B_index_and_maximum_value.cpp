//
// Created by TheUnicat on 2024-08-30.
//

#include <iostream>
using namespace std;

int t;

int main() {
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        int num, max_num = 0;
        for (int j = 0; j < n; j++) {
            cin >> num;
            max_num = max(max_num, num);
        }

        for (int j = 1; j <= m; j++) {
            char sign;
            int l, r;
            cin >> sign >> l >> r;

            if (sign == '+') {
                if (max_num >= l && max_num <= r) max_num++;
            }
            else if (max_num >= l && max_num <= r) max_num--;

            cout << max_num << " ";
        }
        cout << endl;
    }
}