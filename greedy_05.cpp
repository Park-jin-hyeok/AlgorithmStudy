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

// GPT 풀이
/*
#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    vector<char> stack;

    for (char digit : number) {
        // 현재 숫자가 스택의 top보다 크면 pop하고 k 줄임
        while (!stack.empty() && k > 0 && stack.back() < digit) {
            stack.pop_back();
            k--;
        }
        stack.push_back(digit);
    }

    // k가 남았으면 뒤에서부터 자름 (예: 9999에서 앞에 제거할 게 없을 때)
    while (k > 0) {
        stack.pop_back();
        k--;
    }

    // 결과 조합
    return string(stack.begin(), stack.end());
}

int main() {
    cout << solution("1924", 2) << endl;        // 출력: 94
    cout << solution("1231234", 3) << endl;     // 출력: 3234
    cout << solution("4177252841", 4) << endl;  // 출력: 775841
    return 0;
}
*/