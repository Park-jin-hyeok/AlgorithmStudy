/*
#include <string>
#include <vector>
#include <algorithm>  
#include <iostream>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;

    vector<int> rDist;
    vector<int> rDist_0;
    int min;
    sort(rocks.begin(), rocks.end());

    rDist.push_back(rocks[0]);
    rDist_0.push_back(rocks[0]);
    for (size_t i = 0; i < rocks.size() -1; i++) {
        rDist.push_back(rocks[i + 1] - rocks[i]);
        rDist_0.push_back(rocks[i + 1] - rocks[i]);
    }
    rDist.push_back(distance - rocks[rocks.size() - 1]);
    rDist_0.push_back(distance - rocks[rocks.size() - 1]);

    sort(rDist.begin(), rDist.end());

    while (n > 0) {
        for (size_t i = 0; i < rDist.size(); i++) {
            if (rDist_0[i] == rDist[0]) {
                if (i != 0 && i != rDist_0.size() - 1) {
                    if (rDist_0[i -1] + rDist_0[i] < rDist_0[i + 1] + rDist_0[i]) {
                        rDist_0[i-1] += rDist_0[i];
                        rDist_0.erase(rDist.begin() + i);
                    }
                    else {
                        rDist_0[i + 1] += rDist_0[i];
                        rDist_0.erase(rDist.begin() + i);
                    }
                }
                else if (i == 0) {
                    rDist_0.erase(rDist.begin());
                }
                else {
                    rDist_0.pop_back();
                }
                n--;
            }
            rDist.erase(rDist.begin());
        }
    }

    for (size_t i = 0; i < rDist.size(); i++) {
        cout << rDist[i] << " ";
    }

    return rDist_0[0];
}
*/