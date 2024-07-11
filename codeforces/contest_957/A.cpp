//
// Created by TheUnicat on 2024-07-11.
//

#include <iostream>
using namespace std;

int n;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        for (int j = 0; j < 5; j++) {
            if (a <= b && a <= c) {
                a++;
            }
            else if (b <= a && b <= c) {
                b++;
            }
            else {
                c++;
            }
        }
        cout << a * b * c << endl;
    }
}