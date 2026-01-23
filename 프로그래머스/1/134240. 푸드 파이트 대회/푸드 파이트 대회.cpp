#include <string>
#include <vector>

using namespace std;

/*
    요구사항 - food 벡터 [1, 3, 4, 6]이 들어올 떄, 각 인덱스 i가 i번째 음식, 원소가 개수를 의미
    승리 조건 -  한 선수는 제일 왼쪽에 있는 음식부터 오른쪽으로, 
    다른 선수는 제일 오른쪽에 있는 음식부터 왼쪽으로 순서대로 먹는 방식으로 진행됩니다. 
    중앙에는 물을 배치하고, 물을 먼저 먹는 선수가 승리하게 됩니다.
    
    Idea:
    - 벡터 그대로 생각하는 것이 아니라, 중앙에 물을 두고 벡터 안에 있는 원소들이 나누기 2를 통해 나누어 져있다고 생각
    [ 1, 3, 4, 6 ] ->  3/2 = 1, 4/2 = 2, 6/2 = 3, 1(물), 6/2=3, 4/2=2, 3/2=1 -> 1은 하나 버려짐(나머지)
    
    TODO:
    1. 반복자를 통해 begin + 1 - end까지 돎, 나누기 2 하며 원소 카운트만큼 숫자 출력
    2. 물 출력
    3. 반복자를 통해 rbegin - rend + 1 까지 돎, 나누기 2 하며 원소 카운트 만큼 숫자 출력
*/

string solution(vector<int> food) {
    string answer = "";
    
    // 1. 왼쪽 절반 만들기
    int index = 1;
    for (auto it = food.begin() + 1; it != food.end(); ++it)
    {
        int count = *it / 2; // 나누기 2 수행
        for (int i = 0; i < count; i++)
            answer += to_string(index);
        index++; // 증감
    }
    
    answer += '0'; // 어차피 0번은 물 1로 고정
    
    // 2. 오른쪽 절반 만들기
    index = food.size() - 1;
    for (auto it = food.rbegin(); it != food.rend() - 1; ++it)
    {
        int count = *it / 2;
        for (int i = 0; i < count; i++)
            answer += to_string(index);
        index--; // 가감
    }
    return answer;
}