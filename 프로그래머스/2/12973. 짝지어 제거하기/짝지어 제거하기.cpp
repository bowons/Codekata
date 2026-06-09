#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> stk;
    
    for (int i = 0; i < s.length(); i++)    
    {
        // 스택이 비어 있거나, 현재 문자와 같은 문자가 아니면 푸쉬
        if (stk.empty() || stk.top() != s[i])
            stk.push(s[i]);
        else // 현재 문자와 가장 최근 문자가 같다면 팝
            stk.pop();
    }
    
    return stk.empty(); // 비었다면 짝이 맞는 것임
}