//
// Created by TheUnicat on 2024-06-06.
//

#include <iostream>
#include <vector>
using namespace std;

int swaps = 0;
vector<int> numbers;

void swap(int a) {
    int num_one = numbers[a];
    int num_two = numbers[a + 1];

    numbers[a + 1] = num_one;
    numbers[a] = num_two;
    swaps++;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int number;
        cin >> number;
        numbers.push_back(number);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (numbers[j] > numbers[j+1]) {
                swap(j);
            }
        }
    }

    cout << "Array is sorted in " << swaps << " swaps." << endl;
    cout << "First Element: " << numbers[0] << endl;
    cout << "Last Element: " << numbers[n - 1];
}