//
// Created by TheUnicat on 2024-07-28.
//

#include <iostream>
#include <vector>
using namespace std;

int n_movies;

bool movie_cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}

int main() {
    cin >> n_movies;
    vector<pair<int, int> > movies(n_movies);
    for (int i =  0; i < n_movies; i++) cin >> movies[i].first >> movies[i].second;

    sort(movies.begin(), movies.end(), movie_cmp);
    int current_time = 0;
    int movies_watched = 0;
    for (auto movie : movies) {
        if (movie.first >= current_time) {
            current_time = movie.second;
            movies_watched++;
        }
    }
    cout << movies_watched << endl;
}