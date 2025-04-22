#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

	int number = triangle.size(); // 삼각형 최대 사이즈 -1
	vector<vector<int>> maxT(number);

	maxT[0].push_back(triangle[0][0]);

	for (size_t i = 1; i < triangle.size(); i++) {
		for (size_t j = 0; j < triangle[i].size(); j++) {
			if (j > 0 && j < triangle[i].size() - 1) {
				maxT[i].push_back(max(triangle[i][j] + maxT[i -1][j - 1], triangle[i][j] + maxT[i - 1][j]));
			}
			else if (j == 0) {
				maxT[i].push_back(triangle[i][j] + maxT[i - 1][j]);
			}
			else if (j == triangle[i].size() - 1) {
				maxT[i].push_back(triangle[i][j] + maxT[i - 1][j - 1]);
			}
		}
	}

	for (const auto& a : maxT[maxT.size() - 1]) {
		if (answer < a){
			answer = a;
		}
	}
	/*
	for (const auto& a : maxT[maxT.size() - 1]) {
		cout << a << " ";
	}
	*/
    return answer;
}