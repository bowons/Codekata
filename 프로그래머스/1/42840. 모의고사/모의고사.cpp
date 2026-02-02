#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> first = {1, 2, 3, 4, 5};
    vector<int> second = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> third = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    vector<int> answer;
    vector<int> hits(3,0);
    
    for (int i = 0; i < answers.size(); i++)
    {        
        // 각 배열 size 기준 % 연산 해서 순환시켜 hit 개수 체크
        if (first[i % first.size()] == answers[i]) hits[0]++;
        if (second[i % second.size()] == answers[i]) hits[1]++;
        if (third[i % third.size()] == answers[i]) hits[2]++;
    }
    // hit 맞춘 순서 별로 answer에 입력
    
    int maxhit = *max_element(hits.begin(), hits.end());
    
    if (maxhit > 0)
    {
        for (int i = 0; i < 3; i++)
        {
            if (hits[i] == maxhit) // 여러명일 경우 여러번 추가(오름차순)
                answer.push_back(i + 1);
        }
    }
    return answer;
}