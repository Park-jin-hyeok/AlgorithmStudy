#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int newSco = 0;

    while (scoville[0] < K) {
        newSco = scoville[0] + scoville[1] * 2;
        scoville.erase(scoville.begin(),scoville.begin()+2);

        for (size_t i = 0; i < scoville.size(); i++) {
            if (scoville[i] > newSco) {
                scoville.insert(scoville.begin() + i, newSco);
                break;
            }
            else if (i == scoville.size() - 1) {
                scoville.push_back(newSco);
                break;
            }
        }
        answer++;
    }

    return answer;
}
/*
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    // 최소 힙 구성
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

    int mixCount = 0;

    while (pq.size() >= 2 && pq.top() < K) {
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();

        int newFood = first + second * 2;
        pq.push(newFood);
        mixCount++;
    }

    // 루프가 끝났을 때 top이 K 이상인지 확인
    if (!pq.empty() && pq.top() >= K) return mixCount;
    else return -1;
}
*/