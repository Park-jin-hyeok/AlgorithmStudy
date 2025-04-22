#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> stones, int k) {
    int left = 0;
	int right = 0;

	for (size_t i = 0; i < stones.size(); i++) {
		if (right < stones[i]) {
			right = stones[i];
		}
	}

	while (left <= right) {
		int mid = (left + right) / 2;
		int con = 0;

		for (size_t i = 0; i < stones.size(); i++) {
			if (stones[i] - mid > 0) {
				con = 0;
			}
			else {
				con++;
				if (con >= k) {
					right = mid - 1;
					cout << "right: " << right << endl;
					break;
				}
			}

			if (i == stones.size() - 1) {
				left = mid + 1;
				cout << "left: " << left << endl;
			}
		}
	}

    return left;
}