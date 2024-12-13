//
// Created by TheUnicat on 2024-12-12.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, q;
string painting;
vector<int> last_seen(26, -1);
vector<int> prefix, suffix;

int main() {
    cin >> n >> q;
    prefix.resize(n), suffix.resize(n);
    cin >> painting;

    int cost = 0;
    for (int i = 0; i < n; i++) {
        int color = ((int) painting[i]) - 65;
        if (last_seen[color] == -1) {
            cost++;
        }
        else {
            for (int j = 0; j < color; j++) {
                if (last_seen[j] > last_seen[color]) {
                    cost++;
                    break;
                }
            }
        }
        last_seen[color] = i;
        prefix[i] = cost;
    }

    last_seen.clear();
    last_seen.resize(26, -1);
    cost = 0;
    for (int i = n - 1; i >= 0; i--) {
        int color = ((int) painting[i]) - 65;
        if (last_seen[color] == -1) {
            cost++;
        }
        else {
            for (int j = 0; j < color; j++) {
                if (last_seen[j] != -1 && last_seen[j] < last_seen[color]) {
                    cost++;
                    //cout << j << " " << color << " " << painting[i] <<" identities" << endl;
                    break;
                }
            }
        }
        last_seen[color] = i;
        suffix[i] = cost;
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        int total_cost = 0;
        if (l != 1) {
            total_cost += prefix[l - 2];
            //cout << total_cost << endl;
        }
        if (r != n) total_cost += suffix[r];
        //cout << "suffix: " << suffix[r] << endl;
        cout << total_cost << endl;
    }

}

