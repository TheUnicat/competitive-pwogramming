//
// Created by TheUnicat on 2024-08-24.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> stone_costs;
vector<int> heights;
int n;

int compute_cost(int pos) {
    if (stone_costs[pos] != -1) return stone_costs[pos];

    int cost;

    if (pos != n - 2) {
        cost = min(compute_cost(pos + 1) + abs(heights[pos + 1] - heights[pos]), compute_cost(pos + 2) + abs(heights[pos + 2] - heights[pos]));
    }
    else cost = compute_cost(pos + 1) + abs(heights[pos + 1] - heights[pos]);

    stone_costs[pos] = cost;
    return cost;
}

int main() {
    cin >> n;
    stone_costs.resize(n, -1);
    heights.resize(n);
    stone_costs[n - 1] = 0;
    for (int i = 0; i < n; i++) cin >> heights[i];

    cout << compute_cost(0);
}