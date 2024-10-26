//
// Created by TheUnicat on 2024-10-14.
//

#include <iostream>
using namespace std;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int width = 0, height = 0;
        for (int j = 0; j < n; j++) {
            int a, b;
            cin >> a >> b;
            width = max(width, a);
            height = max(height, b);
        }

        cout << 2 * width + 2 * height << endl;
    }
}