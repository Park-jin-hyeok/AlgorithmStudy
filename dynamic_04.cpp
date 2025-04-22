#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> money) {
    int n = money.size();

    vector<int> dp0(n, 0); // case 1: 첫 집 포함, 마지막 집 제외
    vector<int> dp1(n, 0); // case 2: 첫 집 제외, 마지막 집 포함

    // case 1
    dp0[0] = money[0];
    dp0[1] = max(money[0], money[1]);
    for (int i = 2; i < n - 1; i++) {
        dp0[i] = max(dp0[i - 1], dp0[i - 2] + money[i]);
    }

    // case 2
    dp1[1] = money[1];
    for (int i = 2; i < n; i++) {
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + money[i]);
    }

    return max(dp0[n - 2], dp1[n - 1]);
}
