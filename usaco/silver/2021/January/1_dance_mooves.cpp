//
// Created by TheUnicat on 2024-12-12.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int n, k;
vector<pair<int, int>> moves;
vector<int> curr_line;
vector<int> component;
vector<unordered_set<int>> visited_in_cycle;
vector<int> successor;
vector<int> ans;

int main() {
    cin >> n >> k;
    successor.resize(n);
    visited_in_cycle.resize(n);
    curr_line.resize(n);
    ans.resize(n);
    component.resize(n, -1);
    for (int i = 0; i < n; i++) curr_line[i] = i;
    for (int i = 0; i < n; i++) visited_in_cycle[i].insert(i);
    for (int i = 0; i < k; i++) {
        int start, end;
        cin >> start >> end;
        start--, end--;
        moves.emplace_back(start, end);
        visited_in_cycle[curr_line[start]].insert(end);
        visited_in_cycle[curr_line[end]].insert(start);
        int first = curr_line[start], second = curr_line[end];
        curr_line[start] = second;
        curr_line[end] = first;
    }
    for (int i = 0; i < n; i++) {
        successor[i] = curr_line[i];
    }
    for (int i = 0; i < n; i++) {
        if (component[i] == -1) {
            unordered_set<int> seen_places = visited_in_cycle[i];
            int curr_pos = successor[i];
            component[i] = i;
            while (curr_pos != i) {
                component[curr_pos] = i;
                auto it = visited_in_cycle[curr_pos].begin();
                while (it != visited_in_cycle[curr_pos].end()) {
                    seen_places.insert(*it);
                    it++;
                }
                curr_pos = successor[curr_pos];
            }
            ans[i] = seen_places.size();
            curr_pos = successor[i];
            while (curr_pos != i) {
                ans[curr_pos] = seen_places.size();
                curr_pos = successor[curr_pos];
            }
        }
    }

    for (int answer : ans) cout << answer << endl;
}

