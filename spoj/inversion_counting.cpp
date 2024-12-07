//
// Created by TheUnicat on 2024-12-07.
//

#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = unsigned long long;

template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int t, n;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll n_inversions = 0;
        cin >> n;
        Tree<int> os_tree;
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            n_inversions += j - os_tree.order_of_key(num);
            os_tree.insert(num);
        }
        cout << n_inversions << endl;
    }
}