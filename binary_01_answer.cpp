#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());  // 정렬 필수 X (but 관례적으로 함)

    long long left = 1;  // 최소 시간
    long long right = (long long)times.back() * n;  // 최대 시간 (가장 느린 심사관 * 인원 수)
    long long answer = right;  // 일단 최댓값으로 초기화

    while (left <= right) {
        long long mid = (left + right) / 2;  // 중간값 (현재 시간 기준)
        long long num = 0;  // mid 시간 안에 처리할 수 있는 사람 수

        for (size_t i = 0; i < times.size(); i++) {
            num += mid / times[i];  // 각 심사관이 mid 시간동안 처리할 수 있는 사람 수
        }

        if (num >= n) {  // 충분히 처리 가능
            answer = mid;         // 일단 정답 후보 저장
            right = mid - 1;      // 더 짧은 시간 탐색
        }
        else {  // 부족
            left = mid + 1;       // 더 많은 시간 필요
        }
    }

    return answer;
}
