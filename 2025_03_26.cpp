#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> food_times, long long k) {
	int min = k / food_times.size();
	int arr_size = food_times.size();

	int sum = 0;

	for (size_t i = 0; i < food_times.size(); i++) {
		sum += food_times[i];

		if (sum > k) {
			break;
		}
		else if (i == food_times.size() && sum <= k) {
			return -1;
		}
	}


	while (min > 0) {
		for (size_t i = 0; i < food_times.size(); i++) {
			if (food_times[i] > min) {
				food_times[i] -= min;
				k -= min;
			}
			else if (food_times[i] == 0) {
				continue;
			}
			else {
				k -= food_times[i];
				food_times[i] = 0;
				arr_size--;
			}
		}

		if (arr_size == 0) {
			break;
		}

		min = k / arr_size;
	}

	for (size_t i = 0; i < food_times.size(); i++) {
		if (food_times[i] != 0 && k != 0) {
			food_times[i]--;
			k--;
		}

		else if (food_times[i] != 0 && k == 0) {
			return i + 1;
		}
	}
}