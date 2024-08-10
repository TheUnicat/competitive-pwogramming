//
// Created by TheUnicat on 2024-08-10.
//

#include <iostream>
#include <vector>
using namespace std;

int n;
int max_n = 0;
vector<int> pyramid;
vector<bool> pyramid_parity;
int pyramid_top = 0;

bool triangle_val_parity(int a) {
    int b = n - 1;
    while (a > 0) {
        if (a & 1 && !(b & 1)) return true;
        a >>= 1;
        b >>= 1;
    }

    return false;
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num > max_n) max_n = num;
        pyramid.push_back(num);
        pyramid_parity.push_back(triangle_val_parity(i));
    }


    int curr_val = 1;
    while (curr_val <= max_n) {
        bool curr_parity = true;
        for (int i = 0; i < n; i++) {
            if (pyramid[i] & curr_val) {
                if (!(curr_parity == pyramid_parity[i])) curr_parity = false;
                else curr_parity = true;
            }
        }
        if (!curr_parity) pyramid_top += curr_val;
        curr_val *= 2;
    }

    cout << pyramid_top;
}