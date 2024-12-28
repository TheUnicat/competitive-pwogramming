
#include <bits/stdc++.h>
using namespace std;

int n, f;
string contest;
map<string, int> freq;
map<string, bool> included_extra;
set<string> seen;

string get_substr(int i) {
    if (i >= n - 2 || i < 0) return "-1";
    char one = contest[i], two = contest[i + 1], three = contest[i + 2];
    string substr = string(1, one);
    substr += two;
    substr += three;
    return substr;
}

int main() {
    cin >> n >> f;
    cin >> contest;
    for (int i = 0; i < n - 2; i++) {
        char one = contest[i], two = contest[i + 1], three = contest[i + 2];
        string substr = get_substr(i);
        if (one != two && (two == three)) {
            seen.insert(substr);
            freq[substr]++;
            for (int j = 97; j < 123; j++) {
                if (((char) j) != one && (char) j != two) {
                    string new_substr = substr;
                    new_substr[0] = (char) j;
                    if (included_extra[new_substr] == false && get_substr(i - 2) != new_substr && get_substr(i - 1) != new_substr) {
                        included_extra[new_substr] = true;
                        seen.insert(new_substr);
                        freq[new_substr]++;
                    }
                }
            }
        }
        else if (one == two && two == three) {
            for (int j = 97; j < 123; j++) {
                if ((char) j != one) {
                    string new_substr = substr;
                    new_substr[0] = (char) j;
                    if (included_extra[new_substr] == false && get_substr(i - 1) != new_substr && get_substr(i - 2) != new_substr) {
                        included_extra[new_substr] = true;
                        seen.insert(new_substr);
                        freq[new_substr]++;
                    }
                }
            }
        }
        else if (one == two && two != three) {
            string new_substr = substr;
            new_substr[1] = three;
            if (included_extra[new_substr] == false && get_substr(i + 1) != new_substr && get_substr(i - 1) != new_substr) {
                included_extra[new_substr] = true;
                seen.insert(new_substr);
                freq[new_substr]++;
            }
        }
        else if (one == three && two != three) {
            string new_substr = substr;
            new_substr[2] = two;
            if (included_extra[new_substr] == false && get_substr(i + 2) != new_substr) {
                included_extra[new_substr] = true;
                seen.insert(new_substr);
                freq[new_substr]++;
            }
        }
    }

    auto it = seen.begin();
    vector<string> ans;
    while (it != seen.end()) {
        //cout << (freq[(*it)]) << " " << *it << endl;
        if (freq[(*it)] >= f) {
            ans.push_back((*it));
        }
        it++;
    }
    cout << ans.size() << endl;
    for (auto answer : ans) cout << answer << endl;
}

