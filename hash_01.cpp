#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int, int> hashmap;

    for (const int&num : nums) {
        hashmap[num]++;
    }

    int number = nums.size() / 2;

    for (auto num : hashmap) {
        cout << num.first << ":" << num.second << " ";
    }

    cout << endl << "hashmap size: " << hashmap.size();

    
    int answer = (number < hashmap.size()) ? number : hashmap.size();

    return answer;
}


//unordered_map 대신 unordered_set 도 가능
//여기선 실제 개수는 중요하지 않고, 중복 없는 종류 수만 필요하니까
//unordered_set을 사용하면 더 간단
//
//unordered_set<int> unique(nums.begin(), nums.end());
//int answer = min(nums.size() / 2, unique.size());
//
//
//
//
//int answer = (number < hashmap.size()) ? number : hashmap.size();
//std::min(a, b) 를 사용하면 더 좋다 
//
//예시) 
//#include <algorithm>
//int answer = min(number, (int)hashmap.size());