//
// Created by TheUnicat on 2024-08-04.
//

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int> > twee;
int highest_value;
int deepest_node;

void twee_twaversal(int start, int prev, int depth) {
    if (depth > highest_value) {
        highest_value = depth;
        deepest_node = start;
    }
    for (int connection : twee[start]) {
        if (connection == prev) continue;
        twee_twaversal(connection, start, depth + 1);
    }
}

int main() {
    cin >> n;
    twee.resize(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int start, end;
        cin >> start >> end;
        twee[start - 1].push_back(end - 1);
        twee[end - 1].push_back(start - 1);
    }

    highest_value = -1;
    deepest_node = -1;
    twee_twaversal(0, -1, 0);

    int copy_deepest_node = deepest_node;
    highest_value = -1;
    deepest_node = -1;
    twee_twaversal(copy_deepest_node, -1, 0);

    cout << highest_value;
}