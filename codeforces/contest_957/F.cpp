//
// Created by TheUnicat on 2024-07-11.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int t;

int main() {
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, x;
        cin >> n >> x;
        int segments = 1;
        set<int> current_things;
        current_things.insert(x);
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            if (x % num != 0) continue;
            if (num == 1) continue;

            for (int quotient : current_things) {
                if (quotient % num == 0) {
                    if (quotient / num == 1) {
                        segments++;
                        current_things.clear();
                        current_things.insert(x);
                        current_things.insert(x / num);
                        break;
                    }
                    current_things.insert(quotient / num);
                }
            }
        }
        cout << segments << endl;
    }
}
