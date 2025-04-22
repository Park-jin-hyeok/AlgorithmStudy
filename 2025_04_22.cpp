#include <string>
#include <vector>

using namespace std;

int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 0;

	int min = 0;
	int waitTime = 0;
	int curTime = 0;
	vector<vector<int>> time(k, vector<int>(1, 0));

	for (size_t i = 0; i < n - k; i++) {
		for (size_t j = 0; j < k; j++) {
			time[j].push_back(0);

			for (size_t k = 0; k < reqs.size(); k++) {
				curTime = reqs[k][0];
				for (size_t i = 0; i < length; i++){

				}
			}

			time[j].pop_back();
		}
	}

    return answer;
}