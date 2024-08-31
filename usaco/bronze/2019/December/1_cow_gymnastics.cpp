//
// Created by TheUnicat on 2024-05-22.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


int main() {
    std::ifstream infile("gymnastics.in");
    int line = 1;
    int k;
    int n;
    int count = 0;
    std::vector<std::vector<int> > exercises;

    std::string line_content;
    while (std::getline(infile, line_content)) {
            if (line == 1) {
                std::istringstream iss(line_content);
                iss >> k >> n;
            } else {
                std::vector<int> exercise_session;
                std::istringstream iss_2(line_content);
                int number;
                while (iss_2 >> number) {
                    exercise_session.push_back(number);
                }
                exercises.push_back(exercise_session);
            }

        line++;
    }
    infile.close();


    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int i_higher = 0;
            bool can_add = true;
            for (std::vector<int> session : exercises) {

                int i_place;
                int j_place;
                for (int l = 0; l <= n; l++) {

                    if (session[l] == i) {
                        i_place = l;
                    }
                    else if (session[l] == j) {
                        j_place = l;
                    }
                }

                if (i_higher == 0) {
                    i_higher = i_place > j_place ? 1 : 2;
                } else {
                    if ((i_place > j_place) && i_higher == 2) {
                        can_add = false;
                    }
                    else if ((j_place > i_place) && i_higher == 1) {
                        can_add = false;
                    }
                }
            }
            if (can_add) {
                count++;
            }
        }
    }

    std::ofstream outfile("gymnastics.out");
    outfile << count;
    outfile.close();
}
