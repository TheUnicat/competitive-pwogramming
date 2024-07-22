//
// Created by TheUnicat on 2024-07-22.
//

#include <iostream>
#include <vector>
using namespace std;

int n, t;
vector<int> books;

int main() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        int minutes;
        cin >> minutes;
        books.push_back(minutes);
    }
    int pointer_one = 0;
    int pointer_two = 0;
    int subarray_sum = 0;
    int max_books = 0;

    while (pointer_one < n) {
        int current_size = pointer_two - pointer_one;
        for (int i = pointer_two; i < n; i++) {
            if (subarray_sum + books[i] > t) {
                pointer_two = i;
                break;
            }
            subarray_sum += books[i];
            current_size++;
        }

        subarray_sum -= books[pointer_one];
        pointer_one++;
        if (current_size > max_books) max_books = current_size;
    }

    cout << max_books;
}
