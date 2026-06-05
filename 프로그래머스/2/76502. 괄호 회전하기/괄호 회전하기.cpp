#include <stack>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char, char> PairMap = {{')', '('},{'}', '{'}, {']', '['}};

bool isValid(string& st, int start)
{
    stack<int> stk;
    unsigned int sz = st.size();
    
    for (int i = 0; i < sz; i++)
    {
        char ch = st[(start + i) % sz]; // 회전을 담당하는 코드
        
        if (PairMap.count(ch)) // 닫힌 괄호임을 확인
        {
            if (stk.empty() || stk.top() != PairMap[ch]) // 스택이 비거나 짝이 맞는지 확인
            {
                return false;
            }
            stk.pop();
        } else // 열린 괄호라면 스택에 집언엏는다
        {
            stk.push(ch);
        }
    }
    
    return stk.empty(); // stk이 empty면 true(다 비었다)
}

int solution(string s) {
    int answer = 0;
    int n = s.size();
    
    for (int i = 0; i < n; i++)
    {
        answer += isValid(s, i);
    }
    
    return answer;
}