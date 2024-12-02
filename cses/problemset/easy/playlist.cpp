//
// Created by TheUnicat on 2024-12-01.
//

#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int n;
vector<int> songs;
map<int, int> song_id_pos;

int main() {
    cin >> n;
    songs.resize(n);
    for (int i = 0; i < n; i++) cin >> songs[i];
    int max_seq_len = 0;
    int curr_pos = 0;
    for (int i = 0; i < n; i++) {
        int curr_song = songs[i];
        if (song_id_pos[curr_song] != 0 && song_id_pos[curr_song] > curr_pos) {
            int temp = song_id_pos[curr_song];
            for (int j = curr_pos; j < song_id_pos[curr_song]; j++) {
                song_id_pos[songs[j]] = 0;
            }
            curr_pos = temp;
        }
        song_id_pos[curr_song] = i + 1;
        max_seq_len = max(max_seq_len, i - curr_pos + 1);
    }

    cout << max_seq_len << endl;
}