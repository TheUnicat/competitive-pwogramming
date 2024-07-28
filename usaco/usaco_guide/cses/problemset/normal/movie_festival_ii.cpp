//
// Created by TheUnicat on 2024-07-28.
//

#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n, k;

bool movie_cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}


int main() {
    cin >> n >> k;

    vector<pair<int, int> > movies;
    multiset<int, greater<int> > members;
    for (int i = 0; i < k; i++) members.insert(0);

    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        movies.push_back(make_pair(start, end));
    }
    sort(movies.begin(), movies.end(), movie_cmp);

    int total_movies_watched = 0;

    for (int i = 0; i < n; i++) {
        pair<int, int> movie = movies[i];
        auto it = members.lower_bound(movie.first);
        if (it == members.end()) continue;

        total_movies_watched++;
        int new_member_time = movie.second;
        members.erase(it);
        members.insert(new_member_time);
    }

    cout << total_movies_watched;
}