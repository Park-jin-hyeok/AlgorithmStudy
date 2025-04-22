#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int bfs(vector<string>& words, string begin, string target) {
    queue<string> q;
    vector<int> dist(words.size() , 0);
    string current = begin;

    for (const auto& word : words) {
        if (word == target) {
            break;
        }
        else if (word == words[words.size() -1]) {
            return 0;
        }
    }
    
    do {
        if (!q.empty()) {
            current = q.front();
            q.pop();
        }

        for (size_t i = 0; i < words.size(); i++) {
            int count = 0;

            if (dist[i] != 0) {
                continue;
            }

            for (size_t j = 0; j < current.length(); j++) {
                if (words[i][j] == current[j]) {
                    count++;
                }
            }

            if (count == current.length() - 1) {
                q.push(words[i]);
                for (size_t k = 0; k < words.size(); k++) {
                    if (words[k] == current) {
                        dist[i] = dist[k] + 1;
                        break;
                    }
                }
            }
        }
    } while (!q.empty());

    for (const auto&d : dist) {
        cout << d << " ";
    }

    int answer = 0;

    for (size_t i = 0; i < words.size(); i++) {
        answer += dist[i];
    }

    return answer;
}

int solution(string begin, string target, vector<string> words) {
    int answer = bfs(words, begin, target);
    return answer;
}