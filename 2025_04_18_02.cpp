#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    vector<bool> deleted(n, false);         // 삭제 여부
    stack<int> deletedStack;                // 삭제된 행 번호 저장

    for (const string& c : cmd) {
        if (c[0] == 'U') {
            int x = stoi(c.substr(2));
            while (x > 0) {
                k--;
                if (!deleted[k]) x--;
            }
        }
        else if (c[0] == 'D') {
            int x = stoi(c.substr(2));
            while (x > 0) {
                k++;
                if (!deleted[k]) x--;
            }
        }
        else if (c[0] == 'C') {
            deleted[k] = true;
            deletedStack.push(k);

            // 아래로 이동
            int next = k + 1;
            while (next < n && deleted[next]) next++;

            if (next < n) k = next;
            else {
                // 아래가 없으면 위로 이동
                int prev = k - 1;
                while (prev >= 0 && deleted[prev]) prev--;
                k = prev;
            }
        }
        else if (c[0] == 'Z') {
            int recover = deletedStack.top(); deletedStack.pop();
            deleted[recover] = false;
        }
    }

    // 결과 구성
    string answer;
    for (int i = 0; i < n; i++) {
        answer += deleted[i] ? 'X' : 'O';
    }

    return answer;
}
