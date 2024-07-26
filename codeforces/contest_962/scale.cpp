//
// Created by TheUnicat on 2024-07-26.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int t;
int num;
string line;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        for (int j = 0; j < n; j++) {
            cin >> line;
            if (j % k == 0) {
                for (int m = 0; m < n; m+=k) {
                    cout << line[m];
                }
                cout << endl;
            }
        }
    }
}