//
// Created by TheUnicat on 2024-07-25.
//

#include <iostream>
#include <set>
#include <string>
using namespace std;

int n;

int main() {
    set<int> change_points;
    string bits;
    cin >> bits;
    multiset<int> gaps;
    change_points.insert(0);
    change_points.insert((int)bits.length());
    for (int i = 1; i < bits.length(); i++) {
        if (bits[i - 1] != bits[i]) {
            change_points.insert(i);
        }
    }

    auto loop_it = change_points.begin();
    loop_it++;
    for (; loop_it != change_points.end(); loop_it++) {
        int higher_point = *loop_it;
        auto lower_it = loop_it;
        lower_it--;
        int lower_point = *lower_it;
        gaps.insert(higher_point - lower_point);
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        int change;
        cin >> change;
        change--;
        auto it = change_points.lower_bound(change);
        cout << "iterator and change value: " << *it << " " << change << endl;
        if (*it == change) {
            if (*it == 0) {
                auto higher_it = it;
                higher_it++;
                int higher_gap = *higher_it - *it;
                int new_gap = higher_gap - 1;
                gaps.erase(gaps.find(higher_gap));
                gaps.insert(new_gap);
                gaps.insert(1);
            }
            else {
                auto lower_it = it;
                lower_it--;
                auto higher_it = it;
                higher_it++;
                int higher_gap = *higher_it - *it;
                int lower_gap = *it - *lower_it;
                cout << "lower_gap " << lower_gap << endl;
                int new_gap = higher_gap + lower_gap + 1;
                gaps.erase(gaps.find(lower_gap));
                gaps.erase(gaps.find(higher_gap));
                gaps.insert(new_gap);
                change_points.erase(change);
                if (higher_gap == 1 && *higher_it != bits.length()) change_points.erase(*higher_it);
                if (lower_gap == 1 && *lower_it != 0) change_points.erase(*lower_it);
            }
        }
        else {
            auto lower_it = it;
            lower_it--;
            int higher_gap;
            int lower_gap;
            int original_gap = *it - *lower_it;
            if (*it - change == 1) {
                if (*it == bits.length()) {
                    higher_gap = 1;
                    lower_gap = original_gap - 1;
                }
                else {
                    auto even_higher_it = it;
                    even_higher_it++;
                    higher_gap = *even_higher_it - *it + 1;
                    lower_gap = original_gap - 1;
                    gaps.erase(gaps.find(*even_higher_it - *it));
                    change_points.erase(it);
                }
            }
            else if (change - *lower_it == 1) {
                if (*lower_it == 0) {
                    higher_gap = original_gap - 1;
                    lower_gap = 1;
                }
                else {
                    auto even_lower_it = it;
                    even_lower_it--;
                    higher_gap = original_gap - 1;
                    lower_gap = change - *even_lower_it + 1;
                    gaps.erase(gaps.find(change - *even_lower_it));
                    change_points.erase(even_lower_it);
                }
            }
            else {
                higher_gap = *it - change - 1;
                lower_gap = change - *lower_it;
                gaps.insert(1);
            }
            gaps.insert(higher_gap);
            gaps.insert(lower_gap);
            gaps.erase(original_gap);
            change_points.insert(change);
        }
        auto last_it = gaps.end();
        last_it--;
        cout << *last_it << " ";
        for (int point : change_points) cout << point <<  " ";
        cout << endl;
    }
}
