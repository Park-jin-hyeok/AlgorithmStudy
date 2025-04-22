#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.rbegin(), people.rend());

    while (people.size() > 0) {
        cout << people[0] << " ";

        if (people[0] + people[people.size() - 1] <= limit && people.size() > 1) {
            people.erase(people.begin());
            people.pop_back();
            answer++;
        }

        else {
            people.erase(people.begin());
            answer++;
        }
    }

    return answer;
}

int main() {
    solution({ 70, 50, 80, 50 }, 100);
    solution({70, 80, 50}, 100);
}