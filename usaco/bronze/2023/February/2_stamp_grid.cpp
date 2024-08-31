//
// Created by TheUnicat on 2024-08-28.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> curr_stamp;
vector<string> curr_grid;
int remaining_uncolored_curr_grid = 0;
int test_cases;
int side_len, stamp_side_len;

bool solve() {
    vector<vector<string> > rotated_stamps;
    rotated_stamps.push_back(curr_stamp);

    vector<string> upside_down(stamp_side_len, string(stamp_side_len, 'a'));
    for (int i = 0; i < stamp_side_len; i++) {
        for (int j = 0; j < stamp_side_len; j++) {
            upside_down[i][j] = curr_stamp[j][stamp_side_len - 1 - i];
        }
    }
    rotated_stamps.push_back(upside_down);

    vector<string> rotated_right(stamp_side_len, string(stamp_side_len, 'a'));
    for (int i = 0; i < stamp_side_len; i++) {
        for (int j = 0; j < stamp_side_len; j++) {
            rotated_right[i][j] = upside_down[j][stamp_side_len - 1 - i];
        }
    }
    rotated_stamps.push_back(rotated_right);

    vector<string> rotated_left(stamp_side_len, string(stamp_side_len, 'a'));
    for (int i = 0; i < stamp_side_len; i++) {
        for (int j = 0; j < stamp_side_len; j++) {
            rotated_left[i][j] = rotated_right[j][stamp_side_len - 1 - i];
        }
    }
    rotated_stamps.push_back(rotated_left);

    while (remaining_uncolored_curr_grid > 0) {
        bool no_progress = true;
        for (auto stamp : rotated_stamps) {
            for (int i = 0; i <= side_len - stamp_side_len; i++) {
                for (int j = 0; j <= side_len - stamp_side_len; j++) {
                    bool effective = false;
                    bool bad = false;
                    for (int k = 0; k < stamp_side_len; k++) {
                        for (int m = 0; m < stamp_side_len; m++) {
                            if (curr_grid[k + i][m + j] == '.' && stamp[k][m] == '*') {
                                bad = true;
                                break;
                            }
                            if (curr_grid[k + i][m + j] == '*' && stamp[k][m] == '*') {
                                effective = true;
                            }
                        }
                        if (bad) break;
                    }
                    if (bad || !effective) continue;

                    no_progress = false;


                    for (int k = 0; k < stamp_side_len; k++) {
                        for (int m = 0; m < stamp_side_len; m++) {
                            if (curr_grid[k + i][m + j] == '*' && stamp[k][m] == '*') {
                                curr_grid[k + i][m + j] = 'd';
                                remaining_uncolored_curr_grid--;
                            }
                        }
                    }
                }
            }
        }
        if (no_progress) return false;
    }

    return true;
}

int main() {
    cin >> test_cases;
    for (int i = 0; i < test_cases; i++) {
        remaining_uncolored_curr_grid = 0;
        cin >> side_len;
        curr_grid.clear();
        curr_grid.resize(side_len, string(side_len, 'a'));
        for (int j = 0; j < side_len; j++) {
            string line;
            cin >> line;
            for (int k = 0; k < side_len; k++) {
                curr_grid[j][k] = line[k];
                if (line[k] == '*') remaining_uncolored_curr_grid++;
            }
        }

        cin >> stamp_side_len;
        curr_stamp.clear();
        curr_stamp.resize(stamp_side_len);
        for (int j = 0; j < stamp_side_len; j++) {
            cin >> curr_stamp[j];
        }

        if (solve()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
