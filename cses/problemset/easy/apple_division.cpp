//
// Created by TheUnicat on 2024-05-27.
//

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

long min_difference = 0;
int n_apples;
long apple_sum = 0;
vector<long> apples;

long calculate_difference(vector<long> batch) {
    long batch_sum = 0;
    for (long integer : batch) {
        batch_sum += integer;
    }


    return abs(apple_sum -  2 * batch_sum);
}

void find_combination(vector<long> current, int start_index) {
    long difference = calculate_difference(current);
    if (difference < min_difference) {
        min_difference = difference;
    }

    for (int i = start_index; i < n_apples; i++) {
        current.push_back(apples[i]);
        find_combination(current, i + 1);
        current.pop_back();
    }
}




int main() {
    cin >> n_apples;
    for (int i = 0; i < n_apples; i++) {
        long apple;
        cin >> apple;
        apples.push_back(apple);
        apple_sum += apple;
    }

    min_difference = apple_sum;

    vector<long> thing;

    find_combination(thing, 0);

    cout << min_difference;
}
