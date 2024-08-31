//
// Created by TheUnicat on 2024-08-21.
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int t;
int mx = 1000000;
vector<int> prime_factors(mx + 1);
vector<bool> is_prime(mx + 1, true);

void populate_primes() {
    for (int i = 2; i <= mx; i++) {
        if (is_prime[i]) {
            prime_factors[i] = i;
            for (int j = i; j <= mx; j += i) {
                is_prime[j] = false;
                prime_factors[j] = i;
            }
        }
    }
}

int count_divisors(int num) {
    int count = 1;

    map<int, int> divisor_count;
    while (num != 1) {
        int factor = prime_factors[num];
        num /= prime_factors[num];
        divisor_count[factor]++;
    }

    for (auto const& [key, value] : divisor_count) {
        count *= (value + 1);
    }

    return count;
}

int main() {
    populate_primes();
    cin >> t;
    for (int i = 0; i < t; i++) {
        int num;
        cin >> num;
        cout << count_divisors(num) << endl;
    }
}

// 120 18
// 18 12
// 12 6
// 6 0