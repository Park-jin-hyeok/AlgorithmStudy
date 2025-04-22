#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> strNums;

    // ���ڸ� ���ڿ��� ��ȯ
    for (int num : numbers) {
        strNums.push_back(to_string(num));
    }

    // ���� (custom compare �Լ� ���)
    sort(strNums.begin(), strNums.end(), compare);

    // ���� ū ���� 0���� �����ϴ� ��� ��ü�� 0�� (��: [0, 0, 0])
    if (strNums[0] == "0") return "0";

    // ���ڿ� �̾� ���̱�
    string answer = "";
    for (const string& s : strNums) {
        answer += s;
    }

    return answer;
}
