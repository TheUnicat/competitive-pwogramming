//
// Created by TheUnicat on 2024-12-11.
//

#include <iostream>
#include <vector>
using namespace std;

int n;

vector<vector<int>> wishlists(500, vector<int>(500));
vector<vector<bool>> floydwarshall(500, vector<bool>(500, false));

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int gift;
            cin >> gift;
            gift--;
            wishlists[i][j] = gift;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            floydwarshall[i][wishlists[i][j]] = true;
            if (wishlists[i][j] == i) break;
        }
    }

    for (int m = 0; m < 1; m++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (floydwarshall[j][i] && floydwarshall[i][k]) {
                        floydwarshall[j][k] = true;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (floydwarshall[wishlists[i][j]][i]) {
                cout << wishlists[i][j] + 1 << endl;
                break;
            }
        }
    }
}
