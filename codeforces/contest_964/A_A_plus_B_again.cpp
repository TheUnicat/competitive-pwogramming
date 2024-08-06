//
// Created by TheUnicat on 2024-08-06.
//

#include <iostream>
#include <string>
using namespace std;

int n;

int main() {
    cin >> n;
    string num;

    for (int i = 0; i < n; i++) {
        cin >> num;
        cout << num[0] - '0' + num[1] - '0' << endl;
    }
}