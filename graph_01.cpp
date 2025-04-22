#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>& win, vector<vector<int>>& lose, vector<pair<int, bool>>& p) {
    queue<pair<int, bool>>& q;

    while (!q.empty) {
    }
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<pair<int, bool>> p(n, { -1, false });
    vector<vector<int>> win(n);
    vector<vector<int>> lose(n);

    for (size_t i = 0; i < p.size(); i++) {
        p[i].first = i;
    }

    for (size_t i = 0; i < results.size(); i++) {
        win[results[i][0] - 1].push_back(results[i][1] - 1);
        lose[results[i][1] - 1].push_back(results[i][0] - 1);
    }

    /*
    for (size_t i = 0; i < win.size(); i++) {
        cout << "win " << i + 1 << " : ";
        for (const auto& a : win[i]) {
            cout << a + 1 << " ";
        }
        cout << endl;
    }

    for (size_t i = 0; i < lose.size(); i++) {
        cout << "lose " << i + 1 << " : ";
        for (const auto& a : win[i]) {
            cout << a + 1 << " ";
        }
        cout << endl;
    }
    */
    return answer;
}