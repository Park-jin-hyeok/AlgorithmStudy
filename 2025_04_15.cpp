#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    vector<vector<pair<int, int>>> a(n, vector<pair<int, int>>(n, {0, 0})); //x + y + 기둥 + 보

    /* 헷갈릴거같아서 그냥 넣어봄
        a[][].first 와같이 사용

        좌표 와 배열
        0 0, 0 1, 0 2, 0 3, 0 4
        1 0, 1 1, 1 2, 1 3, 1 4 

        벡터에서의 위치와 반대
    */

    for (size_t i = 0; i < build_frame.size(); i++) {
        if (build_frame[i][3] == 1) { //기둥 또는 보 추가
            if (build_frame[i][2] == 0) { //기둥 추가
                if (build_frame[i][1] == 0 &&
                    (a[build_frame[i][1]][build_frame[i][0]].first == true ||
                    a[build_frame[i][1]][build_frame[i][0]].second == true)) { //아랫쪽에 기둥이나 보가 있어야함 바닥인 경우도 추가
                    a[build_frame[i][1]][build_frame[i][0]].first = 1;
                    a[build_frame[i][1]][build_frame[i][0]].first = 1;
                }
            }
            else { //보 추가
                if ((a[build_frame[i][1]][build_frame[i][0]].first == true ||
                    a[build_frame[i][1]][build_frame[i][0] + 1].first == true) &&
                    (a[build_frame[i][1]][build_frame[i][0]].second == true &&
                    a[build_frame[i][1]][build_frame[i][0] + 1].second == true)) { //완쪽과 오른쪽 둘중 하나에 기둥이 있거나 둘다 보가 있어야한다
                    a[build_frame[i][1]][build_frame[i][0]].second = true;
                }
            }
        }
        else { //기둥 또는 보 삭제
            if (build_frame[i][2] == 0) { //기둥 삭제
                if (true) { //기둥 삭제 조건

                }
            }
            else { //보 삭제

            }
        }
    }

    return answer;
}