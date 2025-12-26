#include <string>
#include <vector>
#include <string>

using namespace std;

int digit(int num, int i) 
{
    string s = to_string(num);
    return s[s.size() - i] - '0'; // 문자열 s 배열 크기와 i로 인덱스 역연산
}

vector<int> solution(long long n) {
    vector<int> answer;
    
    string s = to_string(n);
    
    for (int i = s.size(); i >= 1; i--) 
    {
        answer.push_back(s[i - 1] - '0');
    }
    
    return answer;
}