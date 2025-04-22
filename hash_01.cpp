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


//unordered_map ��� unordered_set �� ����
//���⼱ ���� ������ �߿����� �ʰ�, �ߺ� ���� ���� ���� �ʿ��ϴϱ�
//unordered_set�� ����ϸ� �� ����
//
//unordered_set<int> unique(nums.begin(), nums.end());
//int answer = min(nums.size() / 2, unique.size());
//
//
//
//
//int answer = (number < hashmap.size()) ? number : hashmap.size();
//std::min(a, b) �� ����ϸ� �� ���� 
//
//����) 
//#include <algorithm>
//int answer = min(number, (int)hashmap.size());