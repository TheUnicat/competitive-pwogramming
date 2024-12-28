#include <iostream>
#include <vector>
using namespace std;

int n, f;
string test;
vector<int> nums;
vector<vector<vector<int>>> freq(26, vector<vector<int>>(26, vector<int>(26, 0)));
vector<vector<vector<bool>>> possible(26, vector<vector<bool>>(26, vector<bool>(26, false)));
vector<vector<vector<bool>>> extra(26, vector<vector<bool>>(26, vector<bool>(26, false)));

bool substrs_same(int one1, int two1, int three1, int second) {
    if (second < 0 || second >= n - 2) return false;
    int one2 = nums[second], two2 = nums[second + 1], three2 = nums[second + 2];
    if (one1 != one2 || two1 != two2 || three1 != three2) return false;
    return true;
}

string make_str(int one, int two, int three) {
    string str = string(1, (char) (one + 97));
    str += (char) (two + 97);
    str += (char) (three + 97);
    return str;
}

void solve() {
    for (int i = 0; i < n - 2; i++) {
        int one2 = nums[i], two2 = nums[i + 1], three2 = nums[i + 2];
        if (one2 != two2 && two2 == three2) {
            freq[one2][two2][three2]++;
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 26; k++) {
                if (freq[i][j][k] >= f) {
                    possible[i][j][k] = true;
                }
            }
        }
    }
}

int main() {
    cin >> n >> f >> test;
    nums.resize(n);
    for (int i = 0; i < n; i++) nums[i] = (int) test[i] - 97;
    if (n > 100) {
        for (int i = 0; i < n - 2; i++) {
            int one = nums[i], two = nums[i + 1], three = nums[i + 2];
            if (one != two && two == three) {
                freq[one][two][three]++;
                for (int j = 0; j < 26; j++) {
                    if (j == one) continue;
                    if (extra[j][two][three] == true) continue;
                    if (!substrs_same(j, two, three, i - 2)) {
                        extra[j][two][three] = true;
                        freq[j][two][three]++;
                    }
                }
            }
            else if (one == two && two == three) {
                for (int j = 0; j < 26; j++) {
                    if (j == one) continue;
                    if (extra[j][two][three] == true) continue;
                    if (!substrs_same(j, two, three, i - 1) && !substrs_same(j, two, three, i - 2)) {
                        extra[j][two][three] = true;
                        freq[j][two][three]++;
                    }
                }
            }
            else if (one == two && two != three) {
                if (extra[one][three][three] == true) continue;
                if (!substrs_same(one, three, three, i + 1)) {
                    extra[one][three][three] = true;
                    freq[one][three][three]++;
                }
            }
            else if (one == three && two != three) {
                if (extra[one][two][two] == true) continue;
                if (!substrs_same(one, two, two, i + 2)) {
                    extra[one][two][two] = true;
                    freq[one][two][two]++;
                }
            }
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    if (freq[i][j][k] >= f) {
                        possible[i][j][k] = true;
                    }
                }
            }
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            int val = nums[i];
            for (int j = 0; j < 26; j++) {
                nums[i] = j;
                for (int m = 0; m < 26; m++) {
                    for (int n = 0; n < 26; n++) {
                        for (int o = 0; o < 26; o++) {
                            freq[m][n][o] = 0;
                        }
                    }
                }

                for (int m = 0; m < n - 2; m++) {
                    int one2 = nums[m], two2 = nums[m + 1], three2 = nums[m + 2];
                    if (one2 != two2 && two2 == three2) {
                        freq[one2][two2][three2]++;
                    }
                }
                for (int m = 0; m < 26; m++) {
                    for (int n = 0; n < 26; n++) {
                        for (int o = 0; o < 26; o++) {
                            if (freq[m][n][o] >= f) {
                                possible[m][n][o] = true;
                            }
                        }
                    }
                }
            }
            nums[i] = val;
        }
    }

    vector<string> ans;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 26; k++) {
                if (possible[i][j][k] == true) {
                    ans.push_back(make_str(i, j, k));
                }
            }
        }
    }

    cout << ans.size() << endl;
    for (string answer : ans) cout << answer << endl;
}