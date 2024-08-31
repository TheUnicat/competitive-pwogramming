//
// Created by TheUnicat on 2024-08-05.
//

#include <iostream>
using namespace std;

int main() {
    int k;
    int trash;

    for (int i = 1; i < 10000; i++) {
        if (i % 2 == 0) {
            cout << "next 1 2 3 4 5 6 7 8 9" << endl;
        }
        else {
            cout << "next 9" << endl;
        }
        cout.flush();

        cin >> k;
        for (int j = 0; j < k; j++) cin >> trash;
        if (k == 2 && i % 2 == 0) break;
    }

    for (int i = 1; i < 10000; i++) {
        cout << "next 0 1 2 3 4 5 6 7 8 9" << endl;
        cout.flush();
        cin >> k;
        if (k == 1) break;
        for (int j = 0; j < k; j++) cin >> trash;
    }

    cin >> trash;
    cout << "done" << endl;
    cout.flush();
}