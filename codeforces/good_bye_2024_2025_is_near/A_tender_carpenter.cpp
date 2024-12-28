//
// Created by TheUnicat on 2024-12-28.
//

#include <iostream>
#include <vector>
using namespace std;

int t, n;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<int> arr(n);
        for (int j = 0; j < n; j++) cin >> arr[j];
        bool ans = true;
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] * 2 > arr[j + 1] && arr[j + 1] * 2 > arr[j]) {
                cout << "YES" << endl;
                ans = false;
                break;
            }
        }

        if (ans == true) cout << "NO" << endl;
    }
}