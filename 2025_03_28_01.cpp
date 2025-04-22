#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
	vector<int> arr = {1};

	int num = 1;
	int len = 1;

	for (size_t i = 0; i < numbers.size(); i++) {
		while (numbers[i] > 1) {
			if (numbers[i] % 2 == 0) {
				arr.push_back(0);
			}
			else {
				arr.push_back(1);
			}
		}
	}

    return answer;
}