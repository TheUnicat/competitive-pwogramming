//
// Created by TheUnicat on 2024-07-15.
//

#include <iostream>
#include <string>
using namespace std;

int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int length;
        string test;
        cin >> length >> test;
        int n_of_1 = 0;
        int contiguous_0s = 0;
        bool previous_number_0 = false;
        for (int j = 0; j < length; j++) {
            if (test[j] == '1') {
                n_of_1++;
                previous_number_0 = false;
            }
            else {
                if (!previous_number_0) contiguous_0s++;
                previous_number_0 = true;
            }
        }
        if (n_of_1 > contiguous_0s) cout << "YES" << endl; else cout << "NO" << endl;
    }
}
