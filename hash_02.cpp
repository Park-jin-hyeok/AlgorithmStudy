//�߸��� �� Ǯ�� ���λ簡 �� �տ� �� ������ ��� Ʋ��

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

/*  GPT Ǯ�� ������ �� �� �� �迭���� ��
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

���⼭ find�� string�� ������ ���° �ִ��� Ȯ�����ִ� �Լ��� �տ� �;��ϴϱ� == 0 �� �Ǿ����
���� �ȿ� �ִ����� Ȯ���Ϸ��� std::npos�� ����Ѵ�
*/