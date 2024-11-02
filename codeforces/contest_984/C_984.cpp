//
// Created by TheUnicat on 2024-11-02.
//

#include <iostream>
#include <vector>
#include <bitset>
#include <string>
using namespace std;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        string line;
        cin >> line;
        int len = (int) line.length();
        int count = 0;
        vector<bool> has_substr(len, false);
        for (int j = 0; j < len - 3; j++) {
            if (line[j] == '1' && line[j + 1] == '1' && line[j + 2] == '0' && line[j + 3] == '0') {
                has_substr[j] = true;
                count++;
            }
        }

        int q;
        cin >> q;
        for (int j = 0; j < q; j++) {
            int pos;
            char new_val;
            cin >> pos >> new_val;
            pos--;
            line[pos] = new_val;
            for (int k = max(0, pos - 3); k < min(pos + 1, len - 3); k++) {
                if (line[k] == '1' && line[k + 1] == '1' && line[k + 2] == '0' && line[k + 3] == '0') {
                    if (has_substr[k]) continue;
                    count++;
                    has_substr[k] = true;
                }
                else if (has_substr[k]) {
                    has_substr[k] = false;
                    count--;
                }
            }

            if (count > 0) cout << "YES";
            else cout << "NO";
            cout << endl;
        }
    }
}