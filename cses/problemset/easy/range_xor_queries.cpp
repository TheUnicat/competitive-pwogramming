//
// Created by TheUnicat on 2024-08-20.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix_xors;
int n, q;

int main() {
    cin >> n >> q;
    prefix_xors.resize(n + 1, 0);
    int current_xor = 0;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;

        current_xor ^= value;
        prefix_xors[i + 1] = current_xor;
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        cout << (prefix_xors[b] ^ prefix_xors[a - 1]) << endl;
    }
}