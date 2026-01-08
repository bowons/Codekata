#include <string>
#include <vector>

using namespace std;

/* 요구사항
    - 입력된 n에 대해 3진법으로 변환, ex ) 45 - 1200_3
    - 완전히 앞뒤로 뒤집을 것 ex ) 0021
    - 그것을 다시 10진법으로 표현할 것
    
    필요 구현
     - 3진법으로 변환할 방법
     - string으로 변환하여 앞뒤로 뒤집을 방법
     - 다시 뒤집힌 string에 대해 10진법으로 변환할 방법
*/

// TODO : n을 받아 3진법 문자를 구성
string get3numeralsystem(int n)
{
    // 나머지를 하나 하나 쌓는다
    // 16 % 2 - 0
    // 8 % 2 - 0
    // 4 % 2 - 0
    // 2 % 2 - 0
    // 1 % 2 - 1 => 뒤집으면? 이미 뒤집혀잇네? 1 0 0 0 0,  3진법도 이와 같다
    
    string res = "";
    while (n > 0)
    {
        res.push_back((n % 3) + '0');
        n /= 3;
    }
    
    return res;
}


// TODO: 3진법 문자를 받아 10진법으로 변환
int get10numeralsystem(string& n) 
{
    // 누적곱? - 분배법칙 이용
    int res = 0;
    
    for (char c : n)
    {
        res = res * 3 + (c - '0');
    }
    
    return res;
}

int solution(int n) {
    string answer = get3numeralsystem(n);
    
    return get10numeralsystem(answer);
}