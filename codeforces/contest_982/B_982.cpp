//
// Created by TheUnicat on 2024-10-14.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        int max_max = 0;
        for (int i = 0; i < n; ++i) cin >> a[i];

        for (int i = 0; i < n; i++) {
            int curr_num = 0;
            for (int j = i + 1; j < n; j++) {
                if (a[j] <= a[i]) curr_num++;
            }

            max_max = max(curr_num, max_max);
        }

        cout << n - max_max - 1 << endl;
    }
    return 0;
}
