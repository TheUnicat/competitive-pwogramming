//
// Created by TheUnicat on 2024-07-24.
//

#include <iostream>
#include <set>
using namespace std;

int x, n;
set<int> lights;
multiset<int> gaps;

int main() {
    cin >> x >> n;
    lights.insert(0);
    lights.insert(x);
    gaps.insert(x);
    gaps.insert(0);
    gaps.insert(0);

    for (int i = 0; i < n; i++) {
        int new_light;
        cin >> new_light;
        auto insertion = lights.insert(new_light);
        auto left_light = insertion.first;
        left_light--;
        auto right_light = insertion.first;
        right_light++;
        int original_gap = *right_light - *left_light;
        int right_gap = *right_light - *insertion.first;
        int left_gap = *insertion.first - *left_light;
        gaps.erase(gaps.find(original_gap));
        gaps.insert(right_gap);
        gaps.insert(left_gap);
        auto it_to_biggest = gaps.end();
        it_to_biggest--;
        //cout << original_gap << " " << right_gap << " " << left_gap << " ";
        cout << *it_to_biggest << endl;
    }
}

