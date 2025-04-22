#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int find(vector<int>& parent, int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent, parent[x]); // 경로 압축
}

void union_sets(vector<int>& parent, int a, int b) {
	a = find(parent, a);
	b = find(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

	vector<int> parent(computers.size());

	/*
	for (int i = 0; i < computers.size(); i++) {
		for (size_t j = 0; j < computers[i].size(); j++) {
			if (computers[i][j] != 0) {
				parent[i] = j;
				break;
			}
		}
	}
	*/
	for (int i = 0; i < n; i++) parent[i] = i;
	
	for (size_t i = 0; i < computers.size(); i++) {
		for (size_t j = 0; j < computers[i].size(); j++) {
			if (i != j && computers[i][j] == 1) {
				union_sets(parent, i, j);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		parent[i] = find(parent, i);
	}

	sort(parent.begin(), parent.end());

	int temp = -1;
	for (int a : parent) {
		if (a != temp){
			answer++;
			temp = a;
		}
	}

    return answer;
}