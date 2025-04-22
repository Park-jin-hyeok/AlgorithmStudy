#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void bfs(const vector<vector<int>>& v, vector<pair<int, bool>>& p) {
    queue<int> q;
    q.push(0); // 0번 == 1번 노드
    p[0].second = true;
    p[0].first = 0;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (size_t i = 0; i < v[front].size(); i++) {
            int next = v[front][i];
            if (p[next].second == false) {
                p[next].second = true;
                p[next].first = p[front].first + 1;
                q.push(next);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    vector<vector<int>> v(n);
    vector<pair<int, bool>> p(n, { 0,false });

    for (const auto& a : edge) {
        v[a[0] - 1].push_back(a[1] - 1);
        v[a[1] - 1].push_back(a[0] - 1);
    }

    bfs(v, p);

    int max = 0;
    for (const auto& a: p) {
        if (a.first > max) {
            max = a.first;
            answer = 1;
        }
        else if (a.first == max) {
            answer++;
        }
    }

    return answer;
}