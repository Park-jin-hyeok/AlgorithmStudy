#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int count(string gem, const vector<string>& gems) {

}

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    unordered_map<string, int> str;
    unordered_map<string, int> str_0;

    for (const auto& gem : gems) {
        str[gem]++;
        str_0[gem]++;
    }

    int forward = 0;
    int back = gems.size() - 1;

    while (true) {
        if (str[gems[back]] - 1 > 0) {
            str[gems[back]]--;
        }
        else {
            break;
        }
        back--;
    }

    while (true) {
        if (str[gems[forward]] - 1 > 0) {
            str[gems[forward]]--;
        }
        else {
            break;
        }
        forward++;
    }

    int length = back - forward;
    int temp_f = forward;
    int temp_b = back;

    int forward = 0;
    int back = gems.size() - 1;

    while (true) {
        if (str_0[gems[forward]] - 1 > 0) {
            str_0[gems[forward]]--;
        }
        else {
            break;
        }
        forward++;
    }
    while (true) {
        if (str_0[gems[back]] - 1 > 0) {
            str_0[gems[back]]--;
        }
        else {
            break;
        }
        back--;
    }

    if (back - forward < length) {
        answer.push_back(forward + 1);
        answer.push_back(back + 1);
    }
    else {
        answer.push_back(temp_f + 1);
    }

    return answer;
}