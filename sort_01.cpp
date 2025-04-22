#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> strNums;

    // 숫자를 문자열로 변환
    for (int num : numbers) {
        strNums.push_back(to_string(num));
    }

    // 정렬 (custom compare 함수 사용)
    sort(strNums.begin(), strNums.end(), compare);

    // 가장 큰 수가 0으로 시작하는 경우 전체가 0임 (예: [0, 0, 0])
    if (strNums[0] == "0") return "0";

    // 문자열 이어 붙이기
    string answer = "";
    for (const string& s : strNums) {
        answer += s;
    }

    return answer;
}
