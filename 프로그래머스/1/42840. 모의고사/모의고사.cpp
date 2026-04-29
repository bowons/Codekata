#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    // 수포자 3명의 패턴을 배열로 먼저 만듬
    
    vector<int> p1 = {1,2,3,4,5};
    vector<int> p2 = {2,1,2,3,2,4,2,5};
    vector<int> p3 = {3,3,1,1,2,2,4,4,5,5};
    
    int n = answers.size();
    
    int p1cnt = 0;
    int p2cnt = 0;
    int p3cnt = 0;
    
    // 배열 길이만큼 순회 돌면서 패턴 크기마다 체크 하면?
    for (int i = 0; i < n; i++)
    {
        if (answers[i] == p1[i % p1.size()]) p1cnt++;
        if (answers[i] == p2[i % p2.size()]) p2cnt++;
        if (answers[i] == p3[i % p3.size()]) p3cnt++;
    }
    
    int maxScore = max({p1cnt, p2cnt, p3cnt});
    
    vector<int> result;
    if (p1cnt == maxScore) result.push_back(1);
    if (p2cnt == maxScore) result.push_back(2);
    if (p3cnt == maxScore) result.push_back(3);
    
    return result;
}