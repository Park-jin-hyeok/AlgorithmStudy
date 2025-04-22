#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<vector<int>> jobs) {
    // �۾� ��û �ð� ���� ����
    sort(jobs.begin(), jobs.end());

    int current_time = 0; // ���� �ð�
    int total_time = 0;   // �� ��ȯ �ð�
    int job_index = 0;    // ó���� �۾� �ε���
    int completed_jobs = 0;

    // �켱���� ť: �ҿ� �ð��� ª�� �۾��� ����
    priority_queue<vector<int>, vector<vector<int>>,
        function<bool(vector<int>, vector<int>)>> pq(
            [](vector<int> a, vector<int> b) {
                if (a[1] == b[1]) return a[0] > b[0]; // ��û �ð� ��
                return a[1] > b[1]; // �ҿ� �ð� ª�� ��
            });

    while (completed_jobs < jobs.size()) {
        // ���� �ð����� ���� �۾��� ��� ť�� �ֱ�
        while (job_index < jobs.size() && jobs[job_index][0] <= current_time) {
            pq.push(jobs[job_index++]);
        }

        if (!pq.empty()) {
            vector<int> job = pq.top(); pq.pop();
            current_time += job[1]; // �۾� �ð���ŭ ���� �ð� ����
            total_time += (current_time - job[0]); // ��ȯ �ð� = ���� �ð� - ��û �ð�
            completed_jobs++;
        }
        else {
            // ����� �۾��� ���ٸ� �ð� 1 ����
            current_time = jobs[job_index][0];
        }
    }

    return total_time / jobs.size();
}

// �ٸ� Ǯ�� �� �̰� ���ϴ� �׳� ����ü ���� ���°�
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Compare ����ü ����
struct Compare {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        if (a[1] == b[1]) return a[0] > b[0]; // �ҿ�ð� ������ ��û�� ���� ��
        return a[1] > b[1]; // �ҿ�ð� ª�� ������ �켱
    }
};

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end()); // ��û �ð� ���� ����

    priority_queue<vector<int>, vector<vector<int>>, Compare> pq;

    int current_time = 0;
    int total_time = 0;
    int job_index = 0;
    int completed_jobs = 0;

    while (completed_jobs < jobs.size()) {
        // ���� �ð����� ���� �۾��� �켱���� ť�� �ֱ�
        while (job_index < jobs.size() && jobs[job_index][0] <= current_time) {
            pq.push(jobs[job_index++]);
        }

        if (!pq.empty()) {
            vector<int> job = pq.top(); pq.pop();
            current_time += job[1];
            total_time += (current_time - job[0]);
            completed_jobs++;
        }
        else {
            current_time = jobs[job_index][0]; // ���� �۾� �ð����� ����
        }
    }

    return total_time / jobs.size();
}

