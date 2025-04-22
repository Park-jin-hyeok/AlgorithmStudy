#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct Compare {
    bool operator()(vector<int>& a, vector<int>& b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    // ������ ���͸� Queue�� �Űܴ�� or ������ ����� �۾��� ���������� ���� ���ٲ��ֱ�
    // ����� �۾��� ���� Heap Queue ����� Queue�� �ҿ�ð��� �ø��������� ����
    // ��û�������� �۾��ҿ�ð��� �����Ŀ� Heap���� pop����
    // �۾��迭�� �ݺ����� ������ �����߰ų� �Űܴ��� Queue�� ������������� ����
    // �Ź� �۾��� ����ɶ� �۾��Ϸ�ð����� ��û�ð��� ���� �ɸ��ð� Ȯ��
    // answer ��� �۾��ð��� �����ְ� �۾��ð��� size��ŭ �����ش�
    // �� ���� �����غ���

    int answer = 0;
    int isJob = 0;
    int time = 0;
    int startTime = 0;
    queue<vector<int>> q_job;
    priority_queue<vector<int>, vector<vector<int>>, Compare> pq;

    for (auto job : jobs) {
        q_job.push(job);
    }

    sort(jobs.begin(), jobs.end());

    while (!pq.empty() || !q_job.empty()) {
        if (!q_job.empty() && q_job.front()[0] == time) {
            pq.push(q_job.front());
            q_job.pop();
        }

        if (!pq.empty() && isJob == 0) {
            //����غ���
            cout << time << " " << startTime << endl;
            answer += (time - startTime);
            isJob += pq.top()[1];
            startTime = pq.top()[0];
            pq.pop();
        }

        ++time;
        --isJob;
    }
    answer = (answer + time + isJob - startTime)/ jobs.size();


    return answer;
}