#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> hashmap;

    int answer = 1;


    // for ���ȿ� �迭�ȿ� ���� ����ϰ� ����item[1]�� Ȯ���ϰ� �̰� stringŸ���̴ϱ� ������ ���� 
    // �ȿ� �־��ְ� hashmap�� �ְ� ������ ������ ���� �߰����ֵ���... �̰� ��¥ �򰥸��� �� ���ϴϱ�
    // ��� Ȯ���ϰ� ���� ������ ������ ���ɷ� �����

    for (const auto& item : clothes) {
        string type = item[1];  // �ǻ� ����
        hashmap[type]++;
    }

    // ����: �� ������ �� �� �ִ��� Ȯ���ϰ� ���� �� ���
    for (const auto& pair : hashmap) {
        answer *= pair.second + 1;
    }

    return answer - 1;
}
