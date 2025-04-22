#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

/*
* �� ������ ��θ� �ѹ� �� ���İ����ϹǷ� BFS ��ĺ��� DFS ����� �� ������ �� ����
vector<string> bfs(const vector<vector<string>>& tickets) {
	queue<vector<string>> q;
	vector<bool> b(tickets.size(), false);	// �̹� �����Դ��� üũ�� �迭
	string current = "ICN";					// ó�� ������ ICN

	q.push(tickets[0]);

	while (!q.empty()) {
		q.pop();

		for (size_t i = 0; i < tickets.size(); i++) {
			if (b[i] == false && tickets[i][0] == current) {

			}
		}
	}
}
*/

vector<int> dfs(const vector<vector<string>>& tickets, string current,vector<int>& b, int num) {

	if (num == tickets.size()) {
		for (const auto a : b) {
			cout << a << " ";
		}
		cout << endl;
		return b;
	}

	for (size_t i = 0; i < tickets.size(); i++) {
		if (b[i] == -1 && tickets[i][0] == current) {
			b[i] = num;
			// cout << "num :" << num << endl;
			dfs(tickets, tickets[i][1], b, num + 1);
		}
	}

	return {0};
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<vector<int>> tanswer;
    vector<string> answer;
    vector<int> temp;
	vector<int> b(tickets.size(), -1);
	string current = "ICN";

	temp = dfs(tickets, current, b, 0);
	
	if (temp.size() == tickets.size()) {
		tanswer.push_back(temp);
	}
	/*
	for (const auto& a: tanswer) {
		for (const auto& b: a) {
			cout << b << " ";
		}
		cout << endl;
	}
	*/
    return answer;
}


#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> answer; // ���� ��� ����
bool finished = false; // ��� ã���� �� �� ���� �ǰ� ó��

// DFS + ��Ʈ��ŷ
void dfs(string cur, vector<vector<string>>& tickets, vector<bool>& visited, vector<string>& path, int depth) {
	if (depth == tickets.size()) {  // Ƽ�� �� ������ ���� ����
		answer = path;              // ���� ��� ����
		finished = true;            // �÷��� ON (ù ��ΰ� ������ ���� ����)
		return;
	}

	for (int i = 0; i < tickets.size(); i++) {
		if (!visited[i] && tickets[i][0] == cur) {  // ���� �� �� Ƽ�� & ������� ���� ��ġ�� ����
			visited[i] = true;                      // �湮 üũ
			path.push_back(tickets[i][1]);          // ��� ���
			dfs(tickets[i][1], tickets, visited, path, depth + 1);  // ��� ȣ��

			if (finished) return;  // ���� ��� ã������ �ٷ� ����

			visited[i] = false;    // ��Ʈ��ŷ - �湮 ����
			path.pop_back();       // ��Ʈ��ŷ - ��� ����
		}
	}
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<bool> visited(tickets.size(), false);  // �湮 üũ �迭
	vector<string> path;                          // ��� ��Ͽ�

	sort(tickets.begin(), tickets.end());  // ������ ���� Ƽ�� ���� ����

	path.push_back("ICN");  // ���� ����
	dfs("ICN", tickets, visited, path, 0);

	return answer;
}
