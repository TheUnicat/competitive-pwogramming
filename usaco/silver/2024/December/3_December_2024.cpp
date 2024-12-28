#include <iostream>
#include <vector>
using namespace std;

int n, q;
vector<vector<char>> grid;
vector<vector<bool>> checked;
vector<vector<bool>> unblocked_this_turn;
vector<vector<bool>> already_blocked;

bool usable(int x, int y) {
    if (checked[x][y]) return false;
    if (already_blocked[x][y]) return false;
    checked[x][y] = true;
    char move = grid[x][y];
    if (x == n - 1) {
        if (move == '.' || move == 'D') return true;
    }
    if (x == 0) {
        if (move == '.' || move == 'U') return true;
    }
    if (y == n - 1) {
        if (move == '.' || move == 'R') return true;
    }
    if (y == 0) {
        if (move == '.' || move == 'L') return true;
    }
    if (move == '.') {
        if (x > 0 && usable(x - 1, y)) return true;
        if (x < n - 1 && usable(x + 1, y)) return true;
        if (y > 0 && usable(x, y - 1)) return true;
        if (y < n - 1 && usable(x, y + 1)) return true;
        return false;
    }
    if (move == 'U') return usable(x - 1, y);
    if (move == 'D') return usable(x + 1, y);
    if (move == 'L') return usable(x, y - 1);
    if (move == 'R') return usable(x, y + 1);
}

void unblock_this_turn(int j, int k) {
    if (j == n || j < 0 || k == n || k < 0) return;
    char move = grid[j][k];
    if (checked[j][k]) return;
    checked[j][k] = true;
    unblocked_this_turn[j][k] = true;
    if (move == '.') {
        if (j + 1 < n && grid[j + 1][k] == '.') unblock_this_turn(j + 1, k);
        if (j - 1 >= 0 && grid[j - 1][k] == '.') unblock_this_turn(j - 1, k);
        if (k + 1< n && grid[j][k + 1] == '.') unblock_this_turn(j, k + 1);
        if (k - 1 >= 0 && grid[j][k - 1] == '.') unblock_this_turn(j, k - 1);
    }
    if (move == 'U') unblock_this_turn(j - 1, k);
    if (move == 'D') unblock_this_turn(j + 1, k);
    if (move == 'L') unblock_this_turn(j, k - 1);
    if (move == 'R') unblock_this_turn(j, k + 1);
}

int main() {
    cin >> n >> q;
    grid.resize(n, vector<char>(n, '.'));
    already_blocked.resize(n, vector<bool>(n, false));
    for (int i = 0; i < q; i++) {
        unblocked_this_turn.clear();
        unblocked_this_turn.resize(n, vector<bool>(n, false));
        //cout << endl << endl;
        int x, y;
        char direction;
        cin >> x >> y >> direction;
        grid[x - 1][y - 1] = direction;
        int blocked = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (already_blocked[j][k]) {
                    blocked++;
                    continue;
                }
                else if (unblocked_this_turn[j][k]) continue;
                checked.clear();
                checked.resize(n, vector<bool>(n, false));
                bool good = usable(j, k);
                if (!good) blocked++;
                if (!good) already_blocked[j][k] = true;
                //cout << good << " ";
                if (good) {
                    checked.clear();
                    checked.resize(n, vector<bool>(n, false));
                    unblock_this_turn(j, k);
                }
            }
            //cout << endl;
        }

        cout << blocked << endl;
    }
}