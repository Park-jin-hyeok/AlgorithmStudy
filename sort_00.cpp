#include <string>
#include <vector>
#include <algorithm>
# include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {

	// array = [1, 5, 2, 6, 3, 7, 4]
	// commands = [[2, 5, 3], [4, 4, 1], [1, 7, 3]]
    vector<int> answer;
	vector<int> temp = {};

	for (size_t i = 0; i < commands.size(); i++) {
		for (size_t j = 0; j < commands[i][1] - commands[i][0] + 1; j++) {
			temp.push_back(array[commands[i][0] - 1 + j]);
		}

		sort(temp.begin(), temp.end());

		for (const auto& arr : temp) {
			cout << temp[arr] << " ";
		}
		cout << endl;

		answer.push_back(temp[commands[i][2] - 1]);

		temp.clear();
	}

    return answer;
}

//answer
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (const auto& cmd : commands) {
		// 구조 분해를 쓸 수도 있고, 그냥 이름 붙여줘도 됨
		int i = cmd[0] - 1;  // 시작 인덱스
		int j = cmd[1];      // 끝 인덱스 (슬라이싱은 끝 포함 안하므로 +1 필요 없음)
		int k = cmd[2] - 1;  // k번째

		// 부분 복사해서 정렬
		vector<int> sub(array.begin() + i, array.begin() + j);
		sort(sub.begin(), sub.end());

		// 결과 저장
		answer.push_back(sub[k]);
	}

	return answer;
}
