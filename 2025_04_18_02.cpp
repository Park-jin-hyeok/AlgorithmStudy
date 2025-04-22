#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    vector<bool> deleted(n, false);         // ���� ����
    stack<int> deletedStack;                // ������ �� ��ȣ ����

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

            // �Ʒ��� �̵�
            int next = k + 1;
            while (next < n && deleted[next]) next++;

            if (next < n) k = next;
            else {
                // �Ʒ��� ������ ���� �̵�
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

    // ��� ����
    string answer;
    for (int i = 0; i < n; i++) {
        answer += deleted[i] ? 'X' : 'O';
    }

    return answer;
}
