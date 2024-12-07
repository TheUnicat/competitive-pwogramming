//
// Created by TheUnicat on 2024-12-07.
//

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<ll> segtree;
int n, q;

void update(ll pos, ll new_val) {
    pos += n;
    segtree[pos] += new_val;
    pos /= 2;
    while (pos > 0) {
        segtree[pos] = segtree[2 * pos] + segtree[2 * pos + 1];
        pos /= 2;
    }
}

ll query(ll l, ll r) {
    ll sum = 0;
    l += n, r += n;
    while (l <= r) {
        if (l % 2 == 1) {
            sum += segtree[l];
            l++;
        }
        if (r % 2 == 0) {
            sum += segtree[r];
            r--;
        }

        l /= 2, r /= 2;
    }

    return sum;
}


int main() {
    cin >> n >> q;
    segtree.resize(2 * n, 0);
    for (int i = 0; i < n; i++) {
        ll num;
        cin >> num;
        segtree[i + n] += num;
        if (i != n - 1) segtree[i + 1 + n] -= num;
    }
    for (int i = n - 1; i > 0; i--) {
        segtree[i] = segtree[2 * i] + segtree[2 * i + 1];
    }

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            ll l, r, added;
            cin >> l >> r >> added;
            update(l - 1, added);
            if (r != n) update(r, -added);
        }
        else {
            ll point;
            cin >> point;
            cout << query(0, point - 1) << endl;
        }
    }
}