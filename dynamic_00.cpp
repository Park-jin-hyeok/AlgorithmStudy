#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int solution(int N, int number) {
    if (N == number) return 1;

    vector<set<int>> dp(9); // index 1~8까지 사용

    for (int i = 1; i <= 8; ++i) {
        // 숫자 N을 i번 이어붙인 수: 예) 5 -> 55, 555
        int repeated = 0;
        for (int j = 0; j < i; ++j) {
            repeated = repeated * 10 + N;
        }
        dp[i].insert(repeated);

        // j + (i-j) 조합을 모두 확인
        for (int j = 1; j < i; ++j) {
            for (int a : dp[j]) {
                for (int b : dp[i - j]) {
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    if (b != 0) dp[i].insert(a / b);
                }
            }
        }

        if (dp[i].count(number)) return i;
    }

    return -1;
}

def solution(N, number) :
    if N == number :
        return 1

        dp = [set() for _ in range(9)]  # dp[1] ~dp[8]

        for i in range(1, 9) :
            dp[i].add(int(str(N) * i))  # 예 : 5, 55, 555 등

            for j in range(1, i) :
                for op1 in dp[j] :
                    for op2 in dp[i - j] :
                        dp[i].add(op1 + op2)
                        dp[i].add(op1 - op2)
                        dp[i].add(op1 * op2)
                        if op2 != 0 :
                            dp[i].add(op1 // op2)

                                if number in dp[i]:
return i

return -1