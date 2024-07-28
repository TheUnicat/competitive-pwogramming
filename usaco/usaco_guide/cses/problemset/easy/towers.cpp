//
// Created by TheUnicat on 2024-07-28.
//

#include <iostream>
#include <set>
using namespace std;

int n;

int main() {
    multiset<int> towers;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        auto it = towers.upper_bound(num);
        if (it != towers.end()) {
            towers.erase(it);
        }
        towers.insert(num);
    }

    cout << towers.size() << endl;
}