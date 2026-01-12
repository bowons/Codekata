#include <bits/stdc++.h>

using namespace std;

// 요굿하항: 조합 문제 - DP
// 순서에 상관 없이 3가지 수를 뽑는다
// 더한 값이 0을 만족하면 cnt를 1 증가

// TODO: 조합을 구하는 함수
// start를 받아 재귀적으로 r개를 선택하고 반환
constexpr int r = 3;
int answer = 0;

void combination(int start, vector<int> cArr, vector<int>& dArr)
{
    if (cArr.size() == r)
    {
        int sum = accumulate(cArr.begin(), cArr.end(), 0);
        if (sum == 0) answer++;
        return;
    }
    
    for (int i = start + 1; i < dArr.size(); i++)
    {
        cArr.push_back(dArr[i]);
        combination(i, cArr, dArr); //선택된 i를 제외하고 i + 1 번째 부터 다시 조합 선택
        cArr.pop_back();
    }
}
    
    
int solution(vector<int> number) {
    answer = 0;
    vector<int> choosen;
    combination(-1, choosen, number);
    
    return answer;
}