//
// Created by TheUnicat on 2024-06-29.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int w_room, h_room;
        int a, b, c, d;
        int w, h;

        cin >> w_room >> h_room;
        cin >> a >> b >> c >> d;
        cin >> w >> h;

        int vertical_distance = max(h_room - d, b);
        int horizontal_distance = max(w_room - c, a);

        if (vertical_distance >= h || horizontal_distance >= w) {
            cout << 0;
        }
        else if (w + c - a > w_room && h + d - b > h_room) {
            cout << -1;
        }
        else {
            int horizontal_shift = w - horizontal_distance;
            int vertical_shift = h - vertical_distance;
            if (w + c - a > w_room) {
                cout << vertical_shift;
            }
            else if (h + d - b > h_room) {
                cout << horizontal_shift;
            }
            else {
                cout << min(vertical_shift, horizontal_shift);
            }
        }
        cout << endl;
    }
}
