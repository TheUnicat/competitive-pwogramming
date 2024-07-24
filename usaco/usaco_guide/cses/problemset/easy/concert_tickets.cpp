//
// Created by TheUnicat on 2024-07-24.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n, m;
multiset<int> tickets;
vector<int> max_prices;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int ticket;
        cin >> ticket;
        tickets.insert(ticket);
    }
    for (int i = 0; i < m; i++) {
        int max_price;
        cin >> max_price;
        max_prices.push_back(max_price);
    }

    for (int i = 0; i < m; i++) {
        if (tickets.empty()) {
            cout << -1 << endl;
            continue;
        }
        auto it = tickets.lower_bound(max_prices[i]);
        if (it == tickets.begin()) {
            if (*it == max_prices[i]) {
                cout << *it << endl;
                tickets.erase(it);
            }
            else {
                cout << -1 << endl;
            }
        }
        else {
            if (*it == max_prices[i]) {
                cout << *it << endl;
                tickets.erase(it);
            }
            else {
                it--;
                cout << *it <<endl;
                tickets.erase(it);
            }
        }
    }
}