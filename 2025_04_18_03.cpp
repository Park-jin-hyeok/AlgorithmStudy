#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    vector<int> arrived;

    int current;

    for (size_t i = 0; i < summits.size(); i++) {
        arrived.push_back(summits[i]);
    }

    for (size_t i = 0; i < summits.size(); i++) {
        current = summits[i];

        while (true) {
            if (find(gates.begin(), gates.end(), current) == gates.end()) {
                return answer;
            }


        }
    }

    return answer;
}