#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> hashmap;

    int answer = 1;


    // for 문안에 배열안에 내가 사용하고 싶은item[1]을 확인하고 이게 string타입이니까 변수를 만들어서 
    // 안에 넣어주고 hashmap에 넣고 같은게 잇으면 개수 추가해주도록... 이거 진짜 헷갈리고 잘 못하니까
    // 계속 확인하고 눈에 익혀서 완전히 내걸로 만들기

    for (const auto& item : clothes) {
        string type = item[1];  // 의상 종류
        hashmap[type]++;
    }

    // 예시: 각 종류가 몇 개 있는지 확인하고 싶을 때 출력
    for (const auto& pair : hashmap) {
        answer *= pair.second + 1;
    }

    return answer - 1;
}
