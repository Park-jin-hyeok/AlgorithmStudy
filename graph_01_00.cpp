#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<vector<int>> win(n);  // i�� �̱� ���� ���
    vector<vector<int>> lose(n); // i�� �� ���� ���

    for (auto& r : results) {
        win[r[0] - 1].push_back(r[1] - 1);
        lose[r[1] - 1].push_back(r[0] - 1);
    }

    // �� �������� ��ü �̱� ������� �� ������ Ž��
    for (int i = 0; i < n; i++) {
        vector<bool> visited(n, false);
        queue<int> q;
        for (int w : win[i]) q.push(w);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            if (!visited[cur]) {
                visited[cur] = true;
                win[i].push_back(cur);  // i�� cur�� �̱�
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
                lose[i].push_back(cur);  // i�� cur���Ե� ��
                for (int next : lose[cur]) q.push(next);
            }
        }
    }

    // win[i].size() + lose[i].size() == n - 1 �� ��츸 ���� Ȯ�� ����
    int answer = 0;
    for (int i = 0; i < n; i++) {
        // �ߺ��� ������� �� ������ set���� �ٲٰų� visited Ȱ�� ����
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
