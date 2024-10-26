//
// Created by TheUnicat on 2024-10-24.
//

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int n, m, q;

int main() {
    cin >> n >> m >> q;
    vector<vector<ll>> dist(n, vector<ll>(n, 10e16));
    for (int i = 0; i < n; i++) dist[i][i] = 0;
    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        dist[a - 1][b - 1] = min(dist[a - 1][b - 1],c);
        dist[b - 1][a - 1] = min(dist[b - 1][a - 1], c);
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (dist[a][b] == (ll) 10e16) cout << -1 << endl;
        else cout << dist[a][b] << endl;
    }
}