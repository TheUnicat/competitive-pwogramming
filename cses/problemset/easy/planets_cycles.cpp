//
// Created by TheUnicat on 2024-08-05.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int n;
vector<int> next_planet;
vector<int> counts;

void dfs(int start) {
    set<int> visited;
    int steps = 0;
    queue<int> planets;

    int curr = start;
    planets.push(curr);

    int repeat;
    while (visited.find(curr) == visited.end() && counts[curr] == 0) {
        visited.insert(curr);
        curr = next_planet[curr];
        planets.push(curr);
        steps++;
    }

    if (counts[curr] != 0) {
        for (int i = 0; i < steps; i++) {
            counts[planets.front()] = counts[curr] + steps - i;
            planets.pop();
        }
        return;
    }
    repeat = curr;
    int cycle_len = 0;

    curr = start;
    while (curr != repeat) {
        cycle_len++;
        curr = next_planet[curr];
    }
    int u = cycle_len;
    cycle_len = steps - cycle_len;

    int count = 0;
    while (count <= steps) {
        if (count < u) {
            counts[planets.front()] = cycle_len + u - count;
        }
        else counts[planets.front()] = cycle_len;
        planets.pop();
        count++;
    }
}


int main() {
    cin >> n;
    next_planet.resize(n);
    counts.resize(n);
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        next_planet[i] = num - 1;
    }

    for (int i = 0; i < n; i++) {
        if (counts[i] == 0) dfs(i);
    }


    for (int i = 0; i < n; i++) cout << counts[i] << " ";
}