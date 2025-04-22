#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int bfs(const vector<vector<int>>& edge, vector<int>& v, queue<vector<int>>& q) {
    int number = 0;

    while (!q.empty()) {
        int first = q.front()[0];

        first = q.front()[1];
        cout << "q : " << q.front()[0] << "," << q.front()[1] << endl;
        q.pop();

        for (size_t i = 0; i < edge.size(); i++) {
            if (edge[i][0] == first && v[edge[i][1] - 1] == 0) {
                q.push(edge[i]);
                v[edge[i][1] - 1] = v[edge[i][0] - 1] + 1;
            }

            number = v[edge[i][0] - 1] + 1;
        }
    }

    int answer = 0;

    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] == number) {
            answer++;
        }
    }

    for (const auto& a : v) {
        cout << a << " ";
    }

    return answer;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    for (size_t i = 0; i < edge.size(); i++) {
        if (edge[i][0] > edge[i][1]) {
            int temp = edge[i][0];
            edge[i][0] = edge[i][1];
            edge[i][1] = temp;
        }
    }

    sort(edge.begin(), edge.end());

    vector<int> v(n, 0);
    queue<vector<int>> q;

    q.push({0, 1});

    answer = bfs(edge, v, q);

    return answer;
}