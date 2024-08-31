//
// Created by TheUnicat on 2024-08-06.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int n;
vector<pair<int, int> > next_cow;
vector<int> inverse;
vector<bool> done;

int min_moo;
ll moos = 0;

void dfs(int start) {
    if (done[start]) return;
    done[start] = true;
    moos += next_cow[start].second;
    if (next_cow[start].second < min_moo) min_moo = next_cow[start].second;

    dfs(next_cow[start].first);
}

int main() {
    cin >> n;
    next_cow.resize(n);
    inverse.resize(n, 0);
    done.resize(n, false);
    for (int i = 0; i < n; i++) {
        int buddy, moo;
        cin >> buddy >> moo;
        next_cow[i] = make_pair(buddy - 1, moo);
        inverse[buddy - 1]++;
    }

    for (int i = 0; i < n; i++) {
        if (done[i]) continue;
        if (inverse[i] == 0) {
            int node = i;
            while (inverse[node] == 0) {
                moos += next_cow[node].second;
                done[node] = true;
                node = next_cow[node].first;
                inverse[node]--;
                if (done[node]) break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (done[i]) continue;
        min_moo = 2000000000;
        dfs(i);
        moos -= min_moo;
    }

    cout << moos << endl;
}