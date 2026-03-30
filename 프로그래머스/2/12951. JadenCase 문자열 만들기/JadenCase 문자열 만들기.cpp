#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

/*
    TODO: 
    1- string stream 통해 공백 기준 토큰 나눠서 받음
    2- 나눠 받은 글자 모두 lower-string으로
    3- 첫글자만 대문자로 upper string 변환
*/

string solution(string s) {
    bool newWord = true;
    
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            newWord = true;
        }
        else
        {
            s[i] = tolower(s[i]);
            if (newWord)
            {
                s[i] = toupper(s[i]);
                newWord = false;
            }
        }
    }
    return s;
}