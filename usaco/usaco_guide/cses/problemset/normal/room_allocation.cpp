//
// Created by TheUnicat on 2024-07-24.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
vector<pair<pair<int, int>, int> > guests;

bool pair_comparator(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    if (a.first.first == b.first.first) {
        return a.first.second > b.first.second;
    }
    return a.first.first < b.first.first;
}

int main() {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > departures;
    departures.push(make_pair(-1, 1));
    cin >> n;
    int max_room_n = 1;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        guests.push_back(make_pair(make_pair(a, b), i + 1));
    }

    vector<pair<pair<int, int>, int> > sorted_guests = guests;
    vector<pair<int, int> > room_numbers;
    sort(sorted_guests.begin(), sorted_guests.end(), pair_comparator);

    int current_room = 0;
    for (auto stay : sorted_guests) {
        int entry_time = stay.first.first;
        int departure_time = stay.first.second;
        if (entry_time > departures.top().first) {
            current_room = departures.top().second;
            departures.pop();
        }
        else {
            current_room = max_room_n + 1;
            if (current_room > max_room_n) max_room_n = current_room;
        }

        departures.push(make_pair(departure_time, current_room));
        room_numbers.push_back(make_pair(stay.second, current_room));
    }

    cout << max_room_n << endl;
    sort(room_numbers.begin(), room_numbers.end());
    for (auto guest : room_numbers) cout << guest.second << endl;
}

