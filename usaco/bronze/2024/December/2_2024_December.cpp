#include <iostream>
#include <vector>
using namespace std;

int n, q;

int main() {
    cin >> n >> q;
    vector<vector<int>> x_axis(n, vector<int>(n, 0));
    vector<vector<int>> y_axis(n, vector<int>(n, 0));
    vector<vector<int>> z_axis(n, vector<int>(n, 0));
    int curr_ans = 0;
    for (int i = 0; i < q; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x_axis[y][z]++;
        if (x_axis[y][z] == n) curr_ans++;
        y_axis[x][z]++;
        if (y_axis[x][z] == n) curr_ans++;
        z_axis[x][y]++;
        if (z_axis[x][y] == n) curr_ans++;
        cout << curr_ans << endl;
    }
}