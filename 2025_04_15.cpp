#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    vector<vector<pair<int, int>>> a(n, vector<pair<int, int>>(n, {0, 0})); //x + y + ��� + ��

    /* �򰥸��Ű��Ƽ� �׳� �־
        a[][].first �Ͱ��� ���

        ��ǥ �� �迭
        0 0, 0 1, 0 2, 0 3, 0 4
        1 0, 1 1, 1 2, 1 3, 1 4 

        ���Ϳ����� ��ġ�� �ݴ�
    */

    for (size_t i = 0; i < build_frame.size(); i++) {
        if (build_frame[i][3] == 1) { //��� �Ǵ� �� �߰�
            if (build_frame[i][2] == 0) { //��� �߰�
                if (build_frame[i][1] == 0 &&
                    (a[build_frame[i][1]][build_frame[i][0]].first == true ||
                    a[build_frame[i][1]][build_frame[i][0]].second == true)) { //�Ʒ��ʿ� ����̳� ���� �־���� �ٴ��� ��쵵 �߰�
                    a[build_frame[i][1]][build_frame[i][0]].first = 1;
                    a[build_frame[i][1]][build_frame[i][0]].first = 1;
                }
            }
            else { //�� �߰�
                if ((a[build_frame[i][1]][build_frame[i][0]].first == true ||
                    a[build_frame[i][1]][build_frame[i][0] + 1].first == true) &&
                    (a[build_frame[i][1]][build_frame[i][0]].second == true &&
                    a[build_frame[i][1]][build_frame[i][0] + 1].second == true)) { //���ʰ� ������ ���� �ϳ��� ����� �ְų� �Ѵ� ���� �־���Ѵ�
                    a[build_frame[i][1]][build_frame[i][0]].second = true;
                }
            }
        }
        else { //��� �Ǵ� �� ����
            if (build_frame[i][2] == 0) { //��� ����
                if (true) { //��� ���� ����

                }
            }
            else { //�� ����

            }
        }
    }

    return answer;
}