#include <string>
#include <vector>
#include <iostream>


using namespace std;

vector<int> dx = { 0, 0, 1, -1 };
vector<int> dy = { 1, -1, 0, 0 };
vector<int> dx0 = { 1, 1, -1, -1, 0, 0, 1, -1 };
vector<int> dy0 = { 1, -1, 1, -1, 1, -1, 0, 0 };

int dfs(vector<vector<int>>& coor, int cx, int cy, int ix, int iy, int count, int min) {
	if (cx == ix && cy == iy) {
		cout << "min: " << min << " count: " << count << endl;
		return count;  // 도착했으니 count 리턴
	}

	int result = 999999;

	for (size_t k = 0; k < 4; k++) {
		int ny = cy + dy[k];
		int nx = cx + dx[k];

		if (coor[ny][nx] == 0) {
			coor[ny][nx] = 1;  // 방문 체크
			int temp = dfs(coor, nx, ny, ix, iy, count + 1, min);
			if (temp < result) result = temp;
			coor[ny][nx] = 0;  // 백트래킹
		}
	}
	return result;
}



int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
	int min = 999999;

	vector<vector<int>> coor(100, vector<int>(100, 2));

	for (size_t i = 0; i < rectangle.size(); i++) {
		for (size_t j = rectangle[i][1] * 2; j <= rectangle[i][3] * 2; j++) {
			for (size_t k = rectangle[i][0] * 2; k <= rectangle[i][2] * 2; k++) {
				coor[j][k] = 1;
			}
		}
	}


	for (size_t i = 0; i < coor.size(); i++) {
		for (size_t j = 0; j < coor.size(); j++) {
			for (size_t k = 0; k < 8; k++) {
				if (coor[i][j] == 1) {
					int ny = i + dy0[k];
					int nx = j + dx0[k];

					if (ny < 0 || nx < 0 || ny >= coor.size() || nx >= coor.size()) continue;
					if (coor[ny][nx] == 1) continue;
					if (coor[ny][nx] == 0) continue;

					coor[i][j] = 0;
					break;
				}
			}
		}
	}
	/*
	for (size_t i = 0; i < coor.size(); i++) {
		for (size_t j = 0; j < coor.size(); j++) {
			cout << coor[i][j] << " ";
		}
		cout << endl;
	}
	*/
	answer = dfs(coor, characterX*2, characterY*2, itemX*2, itemY*2, 0, min);
	cout << "answer: " << answer;
    return answer /2;
}