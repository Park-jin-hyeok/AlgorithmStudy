#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

//��¥ �߸��� �� Ǯ��...

vector<int> solution(vector<string> genres, vector<int> plays) {
	int ver = 0;
	int swapInt = 0;

    vector<int> answer;
	vector<vector<int>> swap;
    vector<vector<vector<int>>> temp; // ù��° �迭�ȿ��� ���� ������ ���ǳ��� ��Ƴ��� �ι�° �迭�����δ� �ε����� �÷��� Ƚ���� ��´�
    vector<string> genVer; // ù��° �迭�ȿ��� ���� ������ ���ǳ��� ��Ƴ��� �ι�° �迭�����δ� �ε����� �÷��� Ƚ���� ��´�
    unordered_map<string, int> hashmap;

	for (size_t i = 0; i < genres.size(); i++) {
		for (size_t t = 0; t < genVer.size(); t++) {
			if (genVer[t] == genres[i]) {
				continue;
			}
			else if (t == genVer.size() - 1) {
				genVer.push_back(genres[i]);
			}
		}
	}

	temp.resize(genVer.size());

	for (int i = 0; i < genres.size()-1; i++) {
		for (size_t t = 0; t < genVer.size(); t++) {
			if (genres[i] == genVer[t]) {
				temp[t].push_back({i, plays[i]});
			}
		}
	}

	for (size_t i = 0; i < genVer.size(); i++) {
		int sum = 0;
		for (size_t t = 0; t < temp[i].size(); t++) {
			sum += temp[i][t][1];
		}
		temp[i].insert(temp[i].begin(), { sum });
	}

	for (size_t i = 0; i < temp.size() - 1; i++) {
		for (size_t t = i + 1; t < temp.size(); t++) {
			if (temp[i][0][0] < temp[t][0][0]) {
				swap = temp[i];
				temp[i] = temp[t];
				temp[t] = swap;
			}
		}
	}

	for (size_t i = 0; i < temp.size(); i++) {
		for (size_t j = 0;  j < temp[i].size()-1;  j++) {
			for (size_t k = j+1; k < temp[i].size(); k++) {
				if (temp[i][j][0] > temp[i][k][0]) {
					swapInt = temp[i][j][0];
					temp[i][j][0] = temp[i][k][0];
					temp[i][k][0] = swapInt;
				}
			}
		}
	}

	for (size_t i = 0; i < temp.size(); i++) {
		for (size_t j = 0; j < temp[i].size(); j++) {
			answer.push_back(temp[i][j][0]);
		}
	}

	// temp = {{{��},{�ε���, ��}, {�ε���, ��}, ...}, {{��},{�ε���, ��}, {�ε���, ��},....}}

	return answer;
}

/*
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
	unordered_map<string, int> genreTotal;  // �帣�� �� ��� ��
	unordered_map<string, vector<pair<int, int>>> genreSongs;  // �帣�� (��� ��, ������ȣ)

	for (int i = 0; i < genres.size(); ++i) {
		genreTotal[genres[i]] += plays[i];
		genreSongs[genres[i]].push_back({plays[i], i});
	}

	// �帣 ����: �� ����� ��������
	vector<pair<string, int>> genreOrder(genreTotal.begin(), genreTotal.end());
	sort(genreOrder.begin(), genreOrder.end(), [](const auto& a, const auto& b) {
		return a.second > b.second;
	});

	vector<int> answer;
	for (const auto& g : genreOrder) {
		string genre = g.first;
		auto& songs = genreSongs[genre];

		// �帣 �� �� ����: ��� �� �������� �� ������ȣ ��������
		sort(songs.begin(), songs.end(), [](const auto& a, const auto& b) {
			if (a.first == b.first) return a.second < b.second;
			return a.first > b.first;
		});

		// ���� 2�� ����
		for (int i = 0; i < songs.size() && i < 2; ++i) {
			answer.push_back(songs[i].second);
		}
	}

	return answer;
}
���� �� Ǯ��;;
*/