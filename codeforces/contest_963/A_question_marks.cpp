//
// Created by TheUnicat on 2024-08-04.
//

#include <iostream>
#include <string>
using namespace std;

int t;
int n;
string test_case;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a = 0, b = 0, c = 0, d = 0;
        cin >> n;
        cin >> test_case;
        for (int j = 0; j < 4 * n; j++) {
            if (test_case[j] == 'A') a++;
            else if (test_case[j] == 'B') b++;
            else if (test_case[j] == 'C') c++;
            else if (test_case[j] == 'D') d++;
        }

        cout << min(n, a) + min (n, b) + min (n, c) + min (n, d) << endl;
    }
}