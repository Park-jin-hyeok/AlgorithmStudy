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
    // 이차원 벡터를 Queue에 옮겨담기 or 변수를 만들고 작업을 넣을때마다 변수 값바꿔주기
    // 대기할 작업을 넣을 Heap Queue 만들기 Queue는 소요시간의 올림차순으로 정리
    // 요청시점에서 작업소요시간이 지난후에 Heap에서 pop진행
    // 작업배열의 반복문이 끝까지 도달했거나 옮겨담은 Queue가 비어있을때까지 진행
    // 매번 작업이 종료될때 작업완료시간에서 요청시간을 빼서 걸린시간 확인
    // answer 모든 작업시간을 더해주고 작업시간의 size만큼 나눠준다
    // 자 이제 시작해보자

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
            //출력해보기
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