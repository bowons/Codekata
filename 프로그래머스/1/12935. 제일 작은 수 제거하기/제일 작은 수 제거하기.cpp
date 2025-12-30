#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 요구사항
// arr에서 가장 작은 수를 제거한 배열을 리턴하라
// 주의사항
// 가장 작은 수를 제거한 배열이 비었으면 -1을 리턴해야함

// 접근법
// 1.arr에서 min을 찾음
// 2. 인덱스를 찾아 erase로 제거
// 3. size 0이면 -1을 채워넣음

vector<int> solution(vector<int> arr) {
    int min_index = min_element(arr.begin(), arr.end()) - arr.begin();
    // 해당 인덱스를 사용하여 erase로 값을 제거
    arr.erase(arr.begin() + min_index);
    
    vector<int> answer;
    
    if (arr.size() == 0)
        answer.push_back(-1);
    else
    {
        for (auto& data : arr)
        {
            answer.push_back(data);
        }
    }
    
    return answer;
}