#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    vector<vector<int>> sorted;
    vector<int> temp;
    int temp0 = n;
    int num = 0;

    for (size_t i = 0; i < info.size() - 1; i++) {
        for (size_t t = i + 1; t < info.size(); t++) {
            if (info[i][0] < info[t][0]) {
                temp = info[i];
                info[i] = info[t];
                info[t] = temp;
            }
            else if (info[i][0] == info[t][0]) {
                if (info[i][1] < info [t][1]) {
                    temp = info[i];
                    info[i] = info[t];
                    info[t] = temp;
                }
            }
        }
    }

    for (size_t i = 0; i < info.size(); i++) {
        if (m - info[i][1] > 1) {
            m = m - info[i][1];
            num = i;
        }
        else {
            break;
        }
    }

    for (size_t i = num; i < info.size(); i++) {
        n = n - info[i][0];
    }

    if (n >= 1) {
        return temp0 - n;
    }
    else {
        return -1;
    }
}