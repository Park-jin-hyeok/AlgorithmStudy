#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    vector<vector<int>> tri(triangle.size());

    tri[0].push_back(triangle[0][0]);

    for (size_t i = 1; i < triangle.size(); i++) {
        for (size_t j = 0; j < triangle[i].size(); j++) {
            if (j == 0) {
                tri[i].push_back(tri[i - 1][0] + triangle[i][0]);
            }
            else if (j == triangle[i].size() - 1) {
                tri[i].push_back(tri[i - 1][j - 1] + triangle[i][j]);
            }
            else {
                tri[i].push_back(max(tri[i - 1][j -1] + triangle[i][j], tri[i - 1][j] + triangle[i][j]));
            }
        }
    }

    /*
    for (size_t i = 0; i < tri.size(); i++) {
        for (size_t j = 0; j < tri[i].size(); j++) {
            cout << tri[i][j] << " ";
        }
        cout << endl;
    }
    */

    for (size_t i = 0; i < tri[tri.size() -1].size(); i++) {
        if (answer < tri[tri.size() - 1][i]) {
            answer = tri[tri.size() - 1][i];
        }
    }

    return answer;
}