//
// Created by TheUnicat on 2025-01-14.
//

#include <iostream>
#include <vector>
using namespace std;

int n, q;
vector<int> rmq;

int query(int l, int r) {
    l += n, r += n;
    int ans = rmq[l];
    while (l <= r) {
        if (l & 1) {
            ans = min(ans, rmq[l]);
            l++;
        }
        if (r % 2 == 0) {
            ans = min(ans, rmq[r]);
            r--;
        }
        l /= 2, r /= 2;
    }
    return ans;
}

int main() {
    cin >> n >> q;
    rmq.resize(2 * n);
    for (int i = 0; i < n; i++) cin >> rmq[n + i];
    for (int i = n - 1; i >= 0; i--) rmq[i] = min(rmq[i * 2], rmq[i * 2 + 1]);
    cout << endl;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << query(l, r - 1) << endl;
    }
}