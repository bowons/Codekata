#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    // 1. arr을 루프를 돈다
    // 2. 벡터의 마지막 원소를 비교해 중복이면 push 하지 않는다.
    for (auto element : arr)
    {
        if (answer.empty() || answer.back() != element)
        {
            answer.push_back(element);    
        }
    }
    
    // 3. 중복이 없는 값만 반환
    
    return answer;
}