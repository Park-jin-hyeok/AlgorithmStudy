#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<vector<int>> win(n);  // i가 이긴 선수 목록
    vector<vector<int>> lose(n); // i가 진 선수 목록

    for (auto& r : results) {
        win[r[0] - 1].push_back(r[1] - 1);
        lose[r[1] - 1].push_back(r[0] - 1);
    }

    // 각 선수별로 전체 이긴 선수들과 진 선수들 탐색
    for (int i = 0; i < n; i++) {
        vector<bool> visited(n, false);
        queue<int> q;
        for (int w : win[i]) q.push(w);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            if (!visited[cur]) {
                visited[cur] = true;
                win[i].push_back(cur);  // i는 cur도 이김
                for (int next : win[cur]) q.push(next);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        vector<bool> visited(n, false);
        queue<int> q;
        for (int l : lose[i]) q.push(l);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            if (!visited[cur]) {
                visited[cur] = true;
                lose[i].push_back(cur);  // i는 cur에게도 짐
                for (int next : lose[cur]) q.push(next);
            }
        }
    }

    // win[i].size() + lose[i].size() == n - 1 인 경우만 순위 확정 가능
    int answer = 0;
    for (int i = 0; i < n; i++) {
        // 중복이 들어있을 수 있으니 set으로 바꾸거나 visited 활용 권장
        sort(win[i].begin(), win[i].end());
        win[i].erase(unique(win[i].begin(), win[i].end()), win[i].end());
        sort(lose[i].begin(), lose[i].end());
        lose[i].erase(unique(lose[i].begin(), lose[i].end()), lose[i].end());

        if (win[i].size() + lose[i].size() == n - 1) {
            answer++;
        }
    }

    return answer;
}
