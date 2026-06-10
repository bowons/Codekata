#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    // 가격이 떨어지지 않은 기간을 저장할 벡터
    vector<int> answer(prices.size());
    
    stack<int> s; // 인덱스를 저장할 스택, 이전 가격과 현재 가격을 비교하기 위함
    int priceNum = prices.size();
    
    for (int i = 0; i < priceNum; i++)  
    {
        // TODO 이전 값과 비교해서 가격이 떨어진 경우 주식을 까먹은 것으로 판단해 인덱스 업뎃
        while (!s.empty() && prices[s.top()] > prices[i])
        {
            // 이전 값보다 작은 경우 반복 시작
            answer[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i); // 인덱스 저장
    }
    
    // 스택에 남은 것들은 가격이 안떨어진 것들이다
    while (!s.empty())
    {
        // 이 경우 마지막 번호는 무조건 0초간 가격 안떨어지므로 마지막 번호 기준 빼기하여 인덱스 저장
        answer[s.top()] = (priceNum - 1) - s.top();
        s.pop();
    }
    
    return answer;
}