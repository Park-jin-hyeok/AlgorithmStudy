#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int left = 0;
    int right = distance;
    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);

    while (left <= right) {
        int mid = (right + left) / 2;
        int prev = 0;
        int removed = 0;

        for (size_t i = 0; i < rocks.size(); i++) {
            if (rocks[i] - prev < mid) {
                removed++;
            }
            else {
                prev = rocks[i];
            }
        }

        if (removed > n) {
            right = mid - 1;
        }
        else {
            answer = mid;
            left = mid + 1;
        }
    }
    return answer;
}