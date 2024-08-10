//
// Created by TheUnicat on 2024-08-10.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<pair<int, int> > nums;

int ask(int a, int b, bool is_or) {
    int result;
    if (is_or) cout << "or " << a << " " << b << endl;
    else cout << "and " << a << " " << b << endl;

    cout.flush();
    cin >> result;

    return result;
}

int find_sum (int a, int b) {
    int or_val = ask(a, b, true);
    int and_val = ask(a, b, false);

    int xor_val = or_val - and_val;

    return (2 * and_val) + xor_val;
}

int main() {
    cin >> n >> k;

    int one_two_sum = find_sum(1, 2);
    int two_three_sum = find_sum(2, 3);
    int one_three_sum = find_sum(1, 3);

    int one_val = (one_two_sum - two_three_sum + one_three_sum) / 2;
    int two_val = one_two_sum - one_val;
    int three_val = two_three_sum - two_val;

    nums.push_back(make_pair(one_val, 1));
    nums.push_back(make_pair(two_val, 2));
    nums.push_back(make_pair(three_val, 3));

    for (int i = 4; i <= n; i++) {
        int three_num_sum = find_sum(3, i);
        nums.push_back(make_pair(three_num_sum - three_val, i));
    }

    sort(nums.begin(), nums.end());

    cout << "finish " << nums[k - 1].first;
}

