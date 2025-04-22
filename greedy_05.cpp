#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";

	while (k > 0) {
		int max = 0;
		
		for (size_t i = 0; i < k + 1; i++) {
			if (int(number[i]) > number[max]) {
				max = i;
			}
		}

		cout << "i = " << max << endl;
		cout << number[max] << " ";

		answer += number[max];

		number = number.substr(max + 1);
		k -= max;
	}

	answer += number;

    return answer;
}

int main() {
	solution("1231234", 3);
}

// GPT Ǯ��
/*
#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    vector<char> stack;

    for (char digit : number) {
        // ���� ���ڰ� ������ top���� ũ�� pop�ϰ� k ����
        while (!stack.empty() && k > 0 && stack.back() < digit) {
            stack.pop_back();
            k--;
        }
        stack.push_back(digit);
    }

    // k�� �������� �ڿ������� �ڸ� (��: 9999���� �տ� ������ �� ���� ��)
    while (k > 0) {
        stack.pop_back();
        k--;
    }

    // ��� ����
    return string(stack.begin(), stack.end());
}

int main() {
    cout << solution("1924", 2) << endl;        // ���: 94
    cout << solution("1231234", 3) << endl;     // ���: 3234
    cout << solution("4177252841", 4) << endl;  // ���: 775841
    return 0;
}
*/