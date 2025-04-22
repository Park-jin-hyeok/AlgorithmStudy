#include <vector>
#include <queue>

using namespace std;

vector<int> dx = { 0, 0, 1, -1 };
vector<int> dy = { 1, -1, 0, 0 };

int bfs(const vector<vector<int>>& maps) {
    int n = maps.size();
    int m = maps[0].size();

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;

    q.push({ 0, 0 });
    dist[0][0] = 1;

    while (!q.empty()) {
        pair<int, int>current = q.front();
        int y = current.first;
        int x = current.second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int ny = y + dy[d];
            int nx = x + dx[d];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (maps[ny][nx] == 0) continue;
            if (dist[ny][nx] != -1) continue;  // 이미 방문했음

            dist[ny][nx] = dist[y][x] + 1;
            q.push({ ny, nx });
        }
    }

    return dist[n - 1][m - 1];  // 도착 못하면 -1 반환
}


int solution(vector<vector<int> > maps) {
    int answer;

    answer = bfs(maps);

    return answer;
}