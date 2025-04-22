#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    int Psize = participant.size();
    string answer;

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (size_t i = 0; i < Psize - 1; ++i) {
        if (participant[i] != completion[i]) {
            answer = participant[i];
            break;
        }
    }

    if (answer == "") {
        answer = participant[Psize - 1];
    }

    return answer;
}