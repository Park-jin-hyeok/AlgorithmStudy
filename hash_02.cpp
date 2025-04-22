//잘못된 내 풀이 접두사가 꼭 앞에 올 이유가 없어서 틀림

#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

	int pSize = phone_book[0].length();

	/*
	for (const auto& num : phone_book) {
		if (phone_book[0] == num) {

		}
	}
	*/

	for (size_t i = 1; i < phone_book.size(); i++) {
		for (size_t t = 0; t < pSize; t++) {
			if (phone_book[i][t] == phone_book[0][t]) {
				if (t == pSize -1) {
					answer = false;
					break;
				}
			}
			else {
				break;
			}
		}
		if (answer == false) {
			break;
		}
	}

    return answer;
}

/*  GPT 풀이 정렬을 한 후 뒷 배열과의 비교
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
	sort(phone_book.begin(), phone_book.end());

	for (size_t i = 0; i < phone_book.size() - 1; ++i) {
		if (phone_book[i + 1].find(phone_book[i]) == 0) {
			return false;
		}
	}
	return true;
}

여기서 find는 string의 내용이 몇번째 있는지 확인해주는 함수로 앞에 와야하니까 == 0 이 되어야함
만약 안에 있는지만 확인하려면 std::npos를 사용한다
*/