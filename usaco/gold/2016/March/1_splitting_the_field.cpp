//
// Created by TheUnicat on 2024-07-21.
//

#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

struct Cow {
    Cow(ll x, ll y) : x(x), y(y) {}
    ll x;
    ll y;

    bool operator<(const Cow& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

bool y_sort(Cow a, Cow b) {
    if (a.y == b.y) {
        return a.x < b.x;
    }
    return a.y < b.y;
}

int n;
vector<Cow> cows_x_sorted;
vector<Cow> cows_y_sorted;
vector<ll> max_y;
vector<ll> max_x;

vector<ll> min_y;
vector<ll> min_x;


int main() {
    ifstream infile("split.in");
    infile >> n;
    vector<ll> max_y_reversed(n);
    vector<ll> max_x_reversed(n);
    vector<ll> min_y_reversed(n);
    vector<ll> min_x_reversed(n);

    for (int i = 0; i < n; i++) {
        ll x, y;
        infile >> x >> y;
        cows_x_sorted.push_back(Cow(x, y));
        cows_y_sorted.push_back(Cow(x, y));
    }
    infile.close();

    sort(cows_x_sorted.begin(), cows_x_sorted.end());
    sort(cows_y_sorted.begin(), cows_y_sorted.end(), y_sort);


    ll max_y_prefix = 0;
    ll max_x_prefix = 0;

    for (Cow cow : cows_x_sorted) {
        if (cow.y > max_y_prefix) max_y_prefix = cow.y;
        max_y.push_back(max_y_prefix);
    }

    for (Cow cow : cows_y_sorted) {
        if (cow.x > max_x_prefix) max_x_prefix = cow.x;
        max_x.push_back(max_x_prefix);
    }

    max_x_prefix = 0;
    max_y_prefix = 0;

    for (int i = n - 1; i >= 0; i--) {
        Cow cow = cows_x_sorted[i];
        if (cow.y > max_y_prefix) max_y_prefix = cow.y;
        max_y_reversed[i] = max_y_prefix;
    }

    for (int i = n - 1; i >= 0; i--) {
        Cow cow = cows_y_sorted[i];
        if (cow.x > max_x_prefix) max_x_prefix = cow.x;
        max_x_reversed[i] = max_x_prefix;
    }

    ll min_y_prefix = 2000000000;
    ll min_x_prefix = 2000000000;

    for (Cow cow : cows_x_sorted) {
        if (cow.y < min_y_prefix) min_y_prefix = cow.y;
        min_y.push_back(min_y_prefix);
    }

    for (Cow cow : cows_y_sorted) {
        if (cow.x < min_x_prefix) min_x_prefix = cow.x;
        min_x.push_back(min_x_prefix);
    }

    min_y_prefix = 2000000000;
    min_x_prefix = 2000000000;

    for (int i = n - 1; i >= 0; i--) {
        Cow cow = cows_x_sorted[i];
        if (cow.y < min_y_prefix) min_y_prefix = cow.y;
        min_y_reversed[i] = min_y_prefix;
    }

    for (int i = n - 1; i >= 0; i--) {
        Cow cow = cows_y_sorted[i];
        if (cow.x < min_x_prefix) min_x_prefix = cow.x;
        min_x_reversed[i] = min_x_prefix;
    }

    ll full_enclosure = (cows_x_sorted[n - 1].x - cows_x_sorted[0].x) * (cows_y_sorted[n - 1].y - cows_y_sorted[0].y);
    ll min_area = full_enclosure;

    //find vertical fences (dividing cows by x-value)
    for (int i = 0; i < n - 1; i++) {
        ll area_one = (max_y[i] - min_y[i]) * (cows_x_sorted[i].x - cows_x_sorted[0].x);
        ll area_two = (max_y_reversed[i + 1] - min_y_reversed[i + 1]) * (cows_x_sorted[n - 1].x - cows_x_sorted[i + 1].x);
        if (area_one + area_two < min_area) {
            min_area = area_one + area_two;
        }
    }

    //find horizontal fences (dividing cows by y-value) :D
    for (int i = 0; i < n - 1; i++) {
        ll area_one = (max_x[i] - min_x[i]) * (cows_y_sorted[i].y - cows_y_sorted[0].y);
        ll area_two = (max_x_reversed[i + 1] - min_x_reversed[i + 1]) * (cows_y_sorted[n - 1].y - cows_y_sorted[i + 1].y);
        if (area_one + area_two < min_area) {
            min_area = area_one + area_two;
        }
    }

    ofstream outfile("split.out");
    outfile << full_enclosure - min_area;
    outfile.close();
    return 0;
}