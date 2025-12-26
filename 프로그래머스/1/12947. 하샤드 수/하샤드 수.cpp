#include <iostream>
#include <string>
#include <vector>

using namespace std;

// index에 맞는 자릿 수를 숫자로 반환
int digit(int num, int index)
{
    string s = to_string(num);
    return s[s.size() - index] - '0';
}

// 각 자릿수로 합을 구해서 하샤드 수인지 아닌지 검사하는 연산 수행
bool solution(int x) {
    bool answer = true;
    
    // 문자열로 변환
    string s = to_string(x);
    
    // 모든 자릿수를 더함
    int sum = 0;
    for (int i = 1; i <= s.size(); i++)
    {
        sum += s[s.size() - i] - '0';
    }
    
    // x를 sum으로 나누어 나누어 떨어지는지 확인
    return x % sum == 0;
}