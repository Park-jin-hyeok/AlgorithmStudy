#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool IsValid(const vector<int>& selected, const vector<vector<int>>& q, const vector<int>& ans) {
    for (size_t i = 0; i < q.size(); i++) {
        for (size_t j = 0; j < selected.size(); j++) {
            if (true) {

            }
        }
    }

    return true;
}


int dfs(int depth, int n, const vector<int>& s, vector<int>& selected, const vector<vector<int>>& q,  const vector<int>& ans) {
    if (selected.size() == n) {
        if (IsValid(selected)) {

        }
    }

    for (size_t i = depth; i < s.size(); i++) {
        selected.push_back(s[i]);
        dfs(i + 1, n, s, selected, q, ans);
        selected.pop_back();
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;

    set<int> s;
    
    vector<int> sorted;
    vector<int> selected;

    for (const auto& a : q) {
        for (const auto b: a) {
            s.insert(b);
        }
    }
    for (const auto& a : sorted) {
        selected.push_back(a);
    }

    return answer;
}