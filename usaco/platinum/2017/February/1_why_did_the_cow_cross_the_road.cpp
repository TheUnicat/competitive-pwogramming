//
// Created by TheUnicat on 2024-12-25.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
using ll = long long;

int n;
ll num, ans = 0;
vector<ll> pos, inversion_arr, segtree, two_pos, inversion_arr_two;

void update(ll val) {
    val += n;
    segtree[val] = 1;
    while (val > 0) {
        val /= 2;
        segtree[val]++;
    }
}

ll query(ll l, ll r) {
    ll sum = 0;
    l += n, r += n;
    while (l <= r) {
        if (l & 1) {
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
    freopen("mincross.in", "r", stdin);
    freopen("mincross.out", "w", stdout);
    cin >> n;
    pos.resize(n), inversion_arr.resize(n), inversion_arr_two.resize(n), two_pos.resize(n);
    segtree.resize(n * 2, 0);
    for (int i = 0; i < n; i++) {
        cin >> num;
        num--;
        pos[num] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> num;
        num--;
        two_pos[num] = i;
        inversion_arr_two[i] = pos[num];
        inversion_arr[pos[num]] = i;
    }

    for (int i = 0; i < n; i++) {
        ans += query(inversion_arr[i] + 1, n - 1);
        update(inversion_arr[i]);
    }
    ll new_ans = ans;
    for (int i = n - 1; i >= 0; i--) {
        new_ans += -n + (2 * inversion_arr[i] + 1);
        ans = min(ans, new_ans);
    }

    ll ans_two = 0;
    segtree.clear();
    segtree.resize(2 * n, 0);
    for (int i = 0; i < n; i++) {
        ans_two += query(inversion_arr_two[i] + 1, n - 1);
        update(inversion_arr_two[i]);
    }
    ans = min(new_ans, ans);
    new_ans = ans_two;
    for (int i = n - 1; i >= 0; i--) {
        new_ans += -n + (2 * inversion_arr_two[i] + 1);
        ans = min(ans, new_ans);
    }

    cout << ans << endl;
}

