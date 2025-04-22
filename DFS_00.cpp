#include <string>
#include <vector>

using namespace std;

void dfs(vector<int> numbers, int sum, int index, int target, int& answer) {
	int temp;

	if (index == numbers.size()) {
		if (sum == target) {
			answer++;
		}
		return;
	}
	dfs(numbers, sum + numbers[index], index + 1, target, answer);
	dfs(numbers, sum - numbers[index], index + 1, target, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

	dfs(numbers, 0, 0, target, answer);

    return answer;
}