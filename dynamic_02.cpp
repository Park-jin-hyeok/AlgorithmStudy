#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    const int MOD = 1e9 + 7;

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (const auto& puddle : puddles) {
        int x = puddle[0] - 1;
        int y = puddle[1] - 1;
        dp[y][x] = -1;
    }

    dp[0][0] = 1;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (dp[y][x] == -1) {
                dp[y][x] = 0;
                continue;
            }
            if (y > 0) dp[y][x] = (dp[y][x] + dp[y - 1][x]) % MOD;
            if (x > 0) dp[y][x] = (dp[y][x] + dp[y][x - 1]) % MOD;
        }
    }

    return dp[n - 1][m - 1];

}

int main() {
    solution(4, 3, { {2,2} });
}