//
// Created by TheUnicat on 2024-10-14.
//

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int max_n = 200000;
int mod_n = 1000000007;
int N, k;
vector<int> C(max_n + 10, 0);

void precompute() {
    C[0] = 1;
    int curr_val = 1;
    for (int i = 1; i < C.size(); i++) {
        curr_val *= 2;
        curr_val %= mod_n;
        C[i] = curr_val;
    }
}

int t;

int main() {
    precompute();
    cin >> t;
    vector<int> ns(t);
    vector<int> ks(t);
    for (int i = 0; i < t; i++) cin >> ns[i];
    for (int i = 0; i < t; i++) cin >> ks[i];
    for (int i = 0; i < t; i++) {
        cout << C[ks[i]] << endl;
    }
}