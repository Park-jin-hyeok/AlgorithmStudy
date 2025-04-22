#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

/*
* 이 문제는 모두를 한번 씩 거쳐가야하므로 BFS 방식보다 DFS 방식이 더 적합할 것 같다
vector<string> bfs(const vector<vector<string>>& tickets) {
	queue<vector<string>> q;
	vector<bool> b(tickets.size(), false);	// 이미 지나왔는지 체크할 배열
	string current = "ICN";					// 처음 시작은 ICN

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

vector<string> answer; // 정답 경로 저장
bool finished = false; // 경로 찾으면 더 안 봐도 되게 처리

// DFS + 백트래킹
void dfs(string cur, vector<vector<string>>& tickets, vector<bool>& visited, vector<string>& path, int depth) {
	if (depth == tickets.size()) {  // 티켓 다 썼으면 종료 조건
		answer = path;              // 정답 경로 복사
		finished = true;            // 플래그 ON (첫 경로가 사전순 가장 빠름)
		return;
	}

	for (int i = 0; i < tickets.size(); i++) {
		if (!visited[i] && tickets[i][0] == cur) {  // 아직 안 쓴 티켓 & 출발지가 현재 위치일 때만
			visited[i] = true;                      // 방문 체크
			path.push_back(tickets[i][1]);          // 경로 기록
			dfs(tickets[i][1], tickets, visited, path, depth + 1);  // 재귀 호출

			if (finished) return;  // 정답 경로 찾았으면 바로 종료

			visited[i] = false;    // 백트래킹 - 방문 원복
			path.pop_back();       // 백트래킹 - 경로 원복
		}
	}
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<bool> visited(tickets.size(), false);  // 방문 체크 배열
	vector<string> path;                          // 경로 기록용

	sort(tickets.begin(), tickets.end());  // 사전순 빠른 티켓 먼저 쓰기

	path.push_back("ICN");  // 시작 공항
	dfs("ICN", tickets, visited, path, 0);

	return answer;
}
