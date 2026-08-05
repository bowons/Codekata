#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    
    // 1. 3개의 큐를 준비한다.
    queue<string> q1, q2, q3;
    
    for (const string& str: cards1) q1.push(str);
    for (const string& str: cards2) q2.push(str);
    for (const string& str: goal) q3.push(str);
    
    // 2. 루프를 돌면서 총 2번을 비교한다
    // index에 해당하는 원소를 goal에서 뽑는다. 그 문자열에 해당하는 내용이 cards1, card2 큐에 없다면. NO.
    // goal을 모두 소모하는데 성공했을 경우 yes
    
    while (!q3.empty())
    {
        if (!q1.empty() && q1.front() == q3.front())
        {
            q1.pop();
            q3.pop();
        }
        else if (!q2.empty() && q2.front() == q3.front())
        {
            q2.pop();
            q3.pop();
        }
        else
        {
            break;
        }
    }
    
    return q3.empty() ? "Yes" : "No";
}