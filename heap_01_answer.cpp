#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<vector<int>> jobs) {
    // 작업 요청 시각 기준 정렬
    sort(jobs.begin(), jobs.end());

    int current_time = 0; // 현재 시각
    int total_time = 0;   // 총 반환 시간
    int job_index = 0;    // 처리할 작업 인덱스
    int completed_jobs = 0;

    // 우선순위 큐: 소요 시간이 짧은 작업이 먼저
    priority_queue<vector<int>, vector<vector<int>>,
        function<bool(vector<int>, vector<int>)>> pq(
            [](vector<int> a, vector<int> b) {
                if (a[1] == b[1]) return a[0] > b[0]; // 요청 시각 비교
                return a[1] > b[1]; // 소요 시간 짧은 순
            });

    while (completed_jobs < jobs.size()) {
        // 현재 시각까지 들어온 작업을 모두 큐에 넣기
        while (job_index < jobs.size() && jobs[job_index][0] <= current_time) {
            pq.push(jobs[job_index++]);
        }

        if (!pq.empty()) {
            vector<int> job = pq.top(); pq.pop();
            current_time += job[1]; // 작업 시간만큼 현재 시각 증가
            total_time += (current_time - job[0]); // 반환 시간 = 끝난 시간 - 요청 시간
            completed_jobs++;
        }
        else {
            // 대기할 작업이 없다면 시간 1 증가
            current_time = jobs[job_index][0];
        }
    }

    return total_time / jobs.size();
}

// 다른 풀이 난 이게 편하다 그냥 구조체 만들어서 쓰는게
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Compare 구조체 정의
struct Compare {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        if (a[1] == b[1]) return a[0] > b[0]; // 소요시간 같으면 요청시 빠른 순
        return a[1] > b[1]; // 소요시간 짧은 순으로 우선
    }
};

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end()); // 요청 시각 기준 정렬

    priority_queue<vector<int>, vector<vector<int>>, Compare> pq;

    int current_time = 0;
    int total_time = 0;
    int job_index = 0;
    int completed_jobs = 0;

    while (completed_jobs < jobs.size()) {
        // 현재 시간까지 들어온 작업들 우선순위 큐에 넣기
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
            current_time = jobs[job_index][0]; // 다음 작업 시간으로 점프
        }
    }

    return total_time / jobs.size();
}

