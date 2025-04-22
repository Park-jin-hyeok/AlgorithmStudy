#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());  // ���� �ʼ� X (but ���������� ��)

    long long left = 1;  // �ּ� �ð�
    long long right = (long long)times.back() * n;  // �ִ� �ð� (���� ���� �ɻ�� * �ο� ��)
    long long answer = right;  // �ϴ� �ִ����� �ʱ�ȭ

    while (left <= right) {
        long long mid = (left + right) / 2;  // �߰��� (���� �ð� ����)
        long long num = 0;  // mid �ð� �ȿ� ó���� �� �ִ� ��� ��

        for (size_t i = 0; i < times.size(); i++) {
            num += mid / times[i];  // �� �ɻ���� mid �ð����� ó���� �� �ִ� ��� ��
        }

        if (num >= n) {  // ����� ó�� ����
            answer = mid;         // �ϴ� ���� �ĺ� ����
            right = mid - 1;      // �� ª�� �ð� Ž��
        }
        else {  // ����
            left = mid + 1;       // �� ���� �ð� �ʿ�
        }
    }

    return answer;
}
