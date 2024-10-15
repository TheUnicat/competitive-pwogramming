//
// Created by TheUnicat on 2024-10-14.
//

#include <iostream>
#include <string>
using namespace std;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        string one, two;
        cin >> one >> two;
        int same = 0;
        for (int j = 0; j < min(one.length(), two.length()); j++) {
            if (one[j] == two[j]) same++;
            else break;
        }

        if (same > 0) same--;

        cout << one.length() + two.length() - same << endl;
    }
}