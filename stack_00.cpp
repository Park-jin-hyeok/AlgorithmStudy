#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int bridge_weight = 0;  // ���� �ٸ� �� �� ����

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
    queue<int> bridge;             // �ٸ� �� Ʈ�� ���� (0�� ����)
    int time = 0;                  // ��� �ð�
    int total_weight = 0;         // ���� �ٸ� �� �� ����
    int idx = 0;                  // ������ �ö� Ʈ�� �ε���

    // �ٸ� ���̸�ŭ �� ���� ä���α� (�ʱ�ȭ)
    for (int i = 0; i < bridge_length; ++i) {
        bridge.push(0);
    }

    while (idx < truck_weights.size()) {
        time++;

        // 1. �ٸ����� Ʈ�� �� ĭ�� ���� (�տ� �ִ� �� pop)
        total_weight -= bridge.front();
        bridge.pop();

        // 2. ���� Ʈ���� �ø� �� �ִ��� Ȯ��
        if (total_weight + truck_weights[idx] <= weight) {
            bridge.push(truck_weights[idx]);
            total_weight += truck_weights[idx];
            idx++;
        } else {
            bridge.push(0);  // Ʈ���� �� �ø��� �� ���� ����
        }
    }

    // ������ Ʈ���� �ٸ��� ������ �ǳʷ��� bridge_length �� �߰�
    return time + bridge_length;
}
���� Ǯ�� �̰͵� ���ƺ��δ�!
*/