//
// Created by TheUnicat on 2024-10-04.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, q;
vector<int> group_val;
vector<pair<int, pair<int, int>>> operations;
vector<pair<pair<int, int>, int>> queries;
vector<int> component_size;
vector<pair<int, int>> answers;

void init() {
    for (int i = 0; i < n; i++) group_val[i] = i;
}

int groupof(int num) {
    if (group_val[num] == num) return num;
    group_val[num] = groupof(group_val[num]);
    return group_val[num];
}

void unite(int a, int b) {
    int a_group = groupof(a), b_group = groupof(b);
    if (component_size[a_group] < component_size[b_group]) {
        group_val[a_group] = b_group;
        component_size[b_group] = component_size[b_group] + component_size[a_group];
    }
    else {
        group_val[b_group] = a_group;
        component_size[a_group] = component_size[b_group] + component_size[a_group];
    }
}

int main() {
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    cin >> n >> q;
    group_val.resize(n);
    component_size.resize(n, 1);
    init();

    for (int i = 0; i < n - 1; i++) {
        int p, q, r;
        cin >> p >> q >> r;
        operations.emplace_back(r, make_pair(p - 1, q - 1));
    }
    sort(operations.begin(), operations.end());

    for (int i = 0; i < q; i++) {
        int k, v;
        cin >> k >> v;
        queries.emplace_back(make_pair(k, v - 1), i);
    }
    sort(queries.begin(), queries.end());

    int curr_q = q - 1;
    int curr_op = n - 2;
    while (curr_q >= 0) {
        int curr_k = queries[curr_q].first.first, curr_v = queries[curr_q].first.second;
        while (operations[curr_op].first >= curr_k) {
            if (curr_op == -1) break;
            unite(operations[curr_op].second.first, operations[curr_op].second.second);
            curr_op--;
        }

        answers.emplace_back(queries[curr_q].second, component_size[groupof(curr_v)] - 1);
        curr_q--;
    }

    sort(answers.begin(), answers.end());
    for (int i = 0; i < q; i++) cout << answers[i].second << endl;
}