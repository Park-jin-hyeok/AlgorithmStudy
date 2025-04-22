#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool Compare(vector<int> &a, vector<int> &b) {
	return a[2] < b[2];
}

int find(vector<int>& parent, int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent, parent[x]); // ��� ����
}

void union_sets(vector<int>& parent, int a, int b) {
	a = find(parent, a);
	b = find(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

z
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
        });

    // 1. parent �迭 �����
    vector<int> parent(n);
    for (int i = 0; i < n; i++) parent[i] = i;

    int num = 0;
    for (int i = 0; i < costs.size(); i++) {
        int u = costs[i][0];
        int v = costs[i][1];
        int cost = costs[i][2];

        // 2. �̹� ����Ǿ� ������ ��ŵ
        if (find(parent, u) == find(parent, v)) continue;

        // 3. ���� + ��� ����
        union_sets(parent, u, v);
        answer += cost;
        num++;
        if (num == n - 1) break; // MST �ϼ�
    }

    return answer;
}
