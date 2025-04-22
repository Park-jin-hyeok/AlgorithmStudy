#include <vector>
#include <string>
#include <iostream>

using namespace std;

int solution(vector<string> arr) {
    int answer = -1;
	int temp = 0;

	vector<int> iArr;

	if (arr[1] == "+") {
		temp = stoi(arr[0]);
	}
	else {
		iArr.push_back(stoi(arr[0]));
	}
	
	for (size_t i = 1; i < arr.size(); i += 2) {
		if (arr[i] == "-") {
			iArr.push_back(stoi(arr[i + 1]) * -1);
			continue;
		}
		else {
			temp += stoi(arr[i + 1]);
		}

		if (i == arr.size() - 1 || arr[i + 2] == "-" && temp != 0) {
			iArr.push_back(temp);
			temp = 0;
		}
	}

	for (int a : iArr) {
		cout << a << " ";
	}

    return answer;
}