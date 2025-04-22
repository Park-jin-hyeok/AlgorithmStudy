#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int bridge_weight = 0;  // 현재 다리 위 총 무게

	vector<pair<int, int>> current;

	while (truck_weights.size() != 0) {
		if (bridge_length > 0 && weight >= truck_weights[0]) {
			weight -= truck_weights[0];
			current.push_back(pair<int, int>(truck_weights[0], bridge_length));

			truck_weights.erase(truck_weights.begin());
		}

		for (size_t i = 0; i < current.size(); i++) {
			current[i].second--;
		}

		if (current[0].second == 0) {
			weight += current[0].first;
			current.erase(current.begin());
		}

		answer++;
	}

    return answer + bridge_length;
}

/*
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> bridge;             // 다리 위 트럭 상태 (0도 포함)
    int time = 0;                  // 경과 시간
    int total_weight = 0;         // 현재 다리 위 총 무게
    int idx = 0;                  // 다음에 올라갈 트럭 인덱스

    // 다리 길이만큼 빈 공간 채워두기 (초기화)
    for (int i = 0; i < bridge_length; ++i) {
        bridge.push(0);
    }

    while (idx < truck_weights.size()) {
        time++;

        // 1. 다리에서 트럭 한 칸씩 전진 (앞에 있는 것 pop)
        total_weight -= bridge.front();
        bridge.pop();

        // 2. 다음 트럭을 올릴 수 있는지 확인
        if (total_weight + truck_weights[idx] <= weight) {
            bridge.push(truck_weights[idx]);
            total_weight += truck_weights[idx];
            idx++;
        } else {
            bridge.push(0);  // 트럭을 못 올리면 빈 공간 유지
        }
    }

    // 마지막 트럭이 다리를 완전히 건너려면 bridge_length 초 추가
    return time + bridge_length;
}
정석 풀이 이것도 좋아보인다!
*/