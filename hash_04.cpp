#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

//진짜 잘못된 내 풀이...

vector<int> solution(vector<string> genres, vector<int> plays) {
	int ver = 0;
	int swapInt = 0;

    vector<int> answer;
	vector<vector<int>> swap;
    vector<vector<vector<int>>> temp; // 첫번째 배열안에는 같은 종류의 음악끼리 모아놓고 두번째 배열안으로는 인덱스와 플레이 횟수를 담는다
    vector<string> genVer; // 첫번째 배열안에는 같은 종류의 음악끼리 모아놓고 두번째 배열안으로는 인덱스와 플레이 횟수를 담는다
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

	// temp = {{{합},{인덱스, 값}, {인덱스, 값}, ...}, {{합},{인덱스, 값}, {인덱스, 값},....}}

	return answer;
}

/*
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
	unordered_map<string, int> genreTotal;  // 장르별 총 재생 수
	unordered_map<string, vector<pair<int, int>>> genreSongs;  // 장르별 (재생 수, 고유번호)

	for (int i = 0; i < genres.size(); ++i) {
		genreTotal[genres[i]] += plays[i];
		genreSongs[genres[i]].push_back({plays[i], i});
	}

	// 장르 정렬: 총 재생수 내림차순
	vector<pair<string, int>> genreOrder(genreTotal.begin(), genreTotal.end());
	sort(genreOrder.begin(), genreOrder.end(), [](const auto& a, const auto& b) {
		return a.second > b.second;
	});

	vector<int> answer;
	for (const auto& g : genreOrder) {
		string genre = g.first;
		auto& songs = genreSongs[genre];

		// 장르 내 곡 정렬: 재생 수 내림차순 → 고유번호 오름차순
		sort(songs.begin(), songs.end(), [](const auto& a, const auto& b) {
			if (a.first == b.first) return a.second < b.second;
			return a.first > b.first;
		});

		// 상위 2곡 수록
		for (int i = 0; i < songs.size() && i < 2; ++i) {
			answer.push_back(songs[i].second);
		}
	}

	return answer;
}
재대로 된 풀이;;
*/