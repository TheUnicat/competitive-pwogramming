//
// Created by TheUnicat on 2024-07-15.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        long long min_damage = 0;
        cin >> a;
        vector<long long> damage(a);
        vector<vector<int> > tree(a, vector<int>(0));
        for (int j = 0; j < a; j++) cin >> damage[j];
        for (int j = 0; j < a - 1; j++) {
            int one, two;
            cin >> one >> two;
            tree[one - 1].push_back(two - 1);
            tree[two - 1].push_back(one - 1);
        }
        while (true) {
            for (long long num : damage) min_damage += num;
            vector<int> monsters_killed_this_round;
            vector<bool> tree_done(a, false);
            int done_trees = 0;
            for (int j = 0; j < a; j++) {
                if (damage[j] == 0) continue;
                if (tree_done[j]) continue;
                long long edge_sum = 0;
                for (int num : tree[j]) edge_sum += !tree_done[num] ? damage[num] : 0;
                if (damage[j] - edge_sum >= 0) {
                    monsters_killed_this_round.push_back(j);
                    tree_done[j] = true;
                    done_trees++;
                    for (int num : tree[j]) tree_done[num] = true; done_trees++;
                }
            }
            while (done_trees < a) {
                long long min_diff = 1;
                bool nothing_done = true;
                int min_index = 0;
                for (int j = 0; j < a; j++) {
                    if (damage[j] == 0) continue;
                    if (tree_done[j]) continue;
                    long long diff = damage[j];
                    for (int num : tree[j]) diff += !tree_done[num] ? damage[num] : 0;
                    if (diff < min_diff) min_diff = diff; min_index = j; nothing_done = false;
                }
                if (nothing_done) break;
                tree_done[min_index] = true;
                done_trees++;
                for (int num : tree[min_index]) tree_done[num] = true; done_trees++;
                monsters_killed_this_round.push_back(min_index);
            }
            for (int num : monsters_killed_this_round) damage[num] = 0;
            if (monsters_killed_this_round.empty()) break;
        }
        cout << min_damage << endl;
    }
}
