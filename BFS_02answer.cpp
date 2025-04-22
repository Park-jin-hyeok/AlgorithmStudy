#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int bfs(const vector<string>& words, string begin, string target) {
    // words안에 target이 있는지 확인
    if (find(words.begin(), words.end(), target) == words.end())
        return 0;

    queue<pair<string, int>> q;  // <현재 단어, 몇 단계>
    vector<bool> visited(words.size(), false);
    q.push({ begin, 0 });

    while (!q.empty()) {
        pair<string, int> cur = q.front();
        string current = cur.first;
        int depth = cur.second;
        q.pop();

        if (current == target) return depth;

        for (size_t i = 0; i < words.size(); i++) {
            if (visited[i]) continue;

            int diff = 0;
            for (size_t j = 0; j < current.length(); j++) {
                if (current[j] != words[i][j]) diff++;
            }

            if (diff == 1) {
                visited[i] = true;
                q.push({ words[i], depth + 1 });
            }
        }
    }

    return 0;
}

int solution(string begin, string target, vector<string> words) {
    return bfs(words, begin, target);
}
