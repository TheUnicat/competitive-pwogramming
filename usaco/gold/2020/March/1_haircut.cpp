//
// Created by TheUnicat on 2024-12-15.
//

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
using ll = long long;

int n, num;
vector<int> segment_tree;
vector<ll> inversion_by_min;

ll query(int a, int b) {
    ll sum = 0;
    a += n, b += n;
    while (a <= b) {
        if (a % 2 == 1) {
            sum += segment_tree[a];
            a++;
        }
        if (b % 2 == 0) {
            sum += segment_tree[b];
            b--;
        }

        a /= 2, b /= 2;
    }

    return sum;
}

void update(int pos) {
     pos += n;
     segment_tree[pos]++;
     pos /= 2;
     while (pos > 0) {
         segment_tree[pos]++;
         pos /= 2;
     }
}

int main() {
    freopen("haircut.in", "r", stdin);
    freopen("haircut.out", "w", stdout);
    cin >> n;
    n++;
    segment_tree.resize(2 * n, 0);
    inversion_by_min.resize(n + 5, 0);
    for (int i = 0; i < n - 1; i++) {
        cin >> num;
        if (num != n) inversion_by_min[num] += query(num + 1, n - 1);
        update(num);
    }
    ll curr_inversions = 0;
    cout << 0 << endl;
    for (int i = 0; i < n - 2; i++) {
        curr_inversions += inversion_by_min[i];
        cout << curr_inversions << endl;
    }
}