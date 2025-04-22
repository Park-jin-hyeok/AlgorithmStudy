#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.rbegin(), citations.rend());

    for (size_t i = 0; i < citations.size(); i++) {
        if (citations[i] > i + 1) {
            if (i == citations.size() - 1) {
                return citations.size();
            }
        }

        else {
            answer = i + 1;
            break;
        }
    }
    return answer;
}

int solution(vector<int> citations) {
    sort(citations.rbegin(), citations.rend()); // 내림차순
    int h = 0;

    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] >= i + 1) {
            h = i + 1;
        }
        else {
            break;
        }
    }

    return h;
}