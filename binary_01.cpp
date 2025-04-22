/*
#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
	int min = 0;

	vector<int> v(times.size(), 0);

	while (n != 0) {
		min = times[0];
		for (size_t i = 0; i < v.size(); i++) {
			if (v[i] == 0) {
				v[i] = times[i];
				n--;
				if (min > v[i]) {
					min = v[i];
				}
			}
			if (min > v[i]) {
				min = v[i];
			}
		}
		cout << "min: " << min << endl;

		for (size_t i = 0; i < v.size(); i++) {
			v[i] -= min;
		}

		answer += min;
		for (const auto& a : v) {
			cout << a << " ";
		}
		cout << endl;
	}
	int max = 0;

	for (size_t i = 0; i < v.size(); i++) {
		if (v.size() > max) {
			max = v.size();
		}
	}

	answer += max;

    return answer;
}
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {

	vector<int> num(times.size(), 0);

	while (n != 0) {
		pair<int, int> temp = {0,times[0] * (num[0] + 1)}; //앞에는 index 뒤에는 개수

		for (size_t i = 1; i < num.size(); i++) {
			if (times[i] * (num[i] + 1) < temp.second) {
				temp.first = i;
				temp.second = times[i] * (num[i] + 1);
			}
		}
		
		for (const auto& a : num) {
			cout << a << " ";
		}
		cout << endl;
		
		num[temp.first]++;
		n--;
	}

	long long max = 0;

	for (size_t i = 0; i < num.size(); i++) {
		if (max < num[i] * times[i]) {
			max = num[i] * times[i];
		}
	}
	return max;
}
