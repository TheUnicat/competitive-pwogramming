//
// Created by TheUnicat on 2024-07-30.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

ll start_x, start_y;
ll end_x, end_y;
ll n;
string weather;
vector<pair<ll, ll> > weather_prefix_sums;

bool days_possible(ll days) {
    ll full_cycles = days / n;
    ll partial_cycle = days % n;
    ll x_movement = weather_prefix_sums[n].first * full_cycles + weather_prefix_sums[partial_cycle].first;
    ll y_movement = weather_prefix_sums[n].second * full_cycles + weather_prefix_sums[partial_cycle].second;

    ll x_distance = abs(end_x - start_x - x_movement);
    ll y_distance = abs((end_y - start_y) - y_movement);
    ll total_distance = x_distance + y_distance;


    if (total_distance <= days) return true;
    return false;
}

int main() {
    cin >> start_x >> start_y;
    cin >> end_x >> end_y;
    cin >> n;
    cin >> weather;

    ll x_sum = 0;
    ll y_sum = 0;
    weather_prefix_sums.push_back(make_pair(x_sum, y_sum));
    for (char day : weather) {
        if (day == 'R') x_sum++;
        else if (day == 'L') x_sum--;
        else if (day == 'U') y_sum++;
        else y_sum--;
        weather_prefix_sums.push_back(make_pair(x_sum, y_sum));
    }


    ll min_k = 1;
    ll max_k = (abs(end_x - start_x) + abs(end_y - start_y)) * (n + 1);
    ll prev_k = -1;
    ll smallest_k = max_k;

    if (!days_possible(max_k)) {
        cout << -1;
        return 0;
    }

    while (max_k >= min_k) {
        ll mid = min_k + (max_k - min_k) / 2;
        if (mid == prev_k) break;
        prev_k = mid;

        if (days_possible(mid)) {
            smallest_k = mid;
            max_k = mid - 1;
        }
        else {
            min_k = mid + 1;
        }
    }

    cout << smallest_k;
}