//
// Created by TheUnicat on 2024-10-13.
//

#include <iostream>
using namespace std;

int t, n;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        int curr = 1;
        while (curr <= n) {
            int first, second, third;
            if (curr + 1 >= n) curr--;
            cout << "? " << curr << " " << curr + 1 << endl;
            cout.flush();
            cin >> first;
            cout << "? " << curr + 1 << " " << curr << endl;
            cout.flush();
            cin >> second;

            if (first == second) {
                curr += 2;
                continue;
            }

            if (curr != 1) third = 1;
            else third = n;

            int third_one, one_third;
            cout << "? " << third << " " << curr << endl;
            cout.flush();
            cin >> third_one;
            cout << "? " << curr << " " << third << endl;
            cout.flush();
            cin >> one_third;

            if (third_one == one_third) {
                cout << "! " << curr + 1 << endl;
            } else cout << "! " << curr << endl;
            cout.flush();
            break;
        }
    }
}

//Truth tables, and stuff owo

// K n;
// 0 0;
//
// K K;
// 1 1;
//
// n n;
// 1 1
//
// I K;
// 1 0;
//
// I n;
// 0 1;
//
// I n K;
// N 1 0
// 0 N 0
// 1 0 N

// n I K;
// N 0 0
// 1 N 0
// 0 1 N

// I K n;
// N 0 1
// 1 N 0
// 0 0 N

//
// I K K;
// N 0 0
// 1 N 1
// 1 1 N
//
// I n n;
// N 1 1
// 0 N 1
// 0 1 N


//NKKKKI
//I N K
//0 0 0