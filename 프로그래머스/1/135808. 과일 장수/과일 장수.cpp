#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
요구사항
1. 사과 점수는 1 to k점까지 존재
2. 한 상자에는 사과를 m개까지 담을 수 있음
3. 사과 한 상자의 가격은, 상자 안 사과 중 가장 낮은 점수 p에 대해 p * m으로 결정

구해야 할 것 - 
1. 한 상자에 가능한 많은 사과를 담아 팔았을 때, 얻을 수 있는 최대 이익은 얻도록 상자를 구상한다
2. 구한 상자를 토대로 가격 산출함

IDEA
- Priority Queue 를 통해 순회를 돌아 m개를 담아 최대 이익을 저장하는 상자를 만든다
*/

// TODO
// 1. pq 선언 - 최대 힙
// 2. score안에 있는 숫자가 없어질 때 까지 m개씩 pop해서 pq에 저장 or score를 pq로 만들어 하나씩 뽑아 m개를 완성
int solution(int k, int m, vector<int> score) {
    priority_queue<int> pq;
    int answer = 0;
    
    for (auto data : score)
        pq.push(data);
    
    vector<int> sumVec;
    int minApple = k;
    while(!pq.empty())
    {
        int num = pq.top();
        pq.pop();

        minApple = num < minApple ? num : minApple;
        
        sumVec.push_back(num);
        if (sumVec.size() == m)
        {
            answer += minApple * m;
            // sumVec을 다시 (m 크기로 초기화)?
            sumVec.clear();
            // 최소값을 다시 k로 갱신
            minApple = k;
        }
    }
    
    return answer;
}