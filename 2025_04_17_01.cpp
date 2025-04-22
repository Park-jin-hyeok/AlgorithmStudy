#include <string>
#include <vector>

using namespace std;

int number = 1;

int dfs(int a, int b, int upDown, const vector<vector<int>>& grid, vector<vector<bool>>& check) {
    check[a][b] = true;

    if (upDown == -1) {
        if (a > 0  && check[a- 1][b] == false) {
            number++;
            dfs(a - 1, b, grid[a - 1][b], grid, check);
        }
        if (b < grid.size() - 1 && check[a][b + 1] == false) {
            number++;
            dfs(a, b + 1, grid[a][b + 1], grid, check);
        }
    }
    else {
        if (a < grid[0].size() - 1 && check[a + 1][b] == false) {
            number++;
            dfs(a + 1, b, grid[a + 1][b], grid, check);
        }
        if (b > 0 && check[a][b - 1] == false) {
            number++;
            dfs(a, b - 1, grid[a][b - 1], grid, check);
        }
    }
}

int solution(vector<vector<int>> grid) {
    int answer = 0;
    vector<vector<bool>> check(grid.size(), vector<bool>(grid[0].size(), false));

    for (size_t i = 0; i < grid.size(); i++) {
        for (size_t j = 0; j < grid[0].size(); j++) {
            dfs(i, j, -1, grid, check);
            if (answer < number) {
                answer = number;
            }
            number = 0;
            dfs(i, j, 1, grid, check);
            if (answer < number) {
                answer = number;
            }
            number = 0;
        }
    }

    return answer;
}