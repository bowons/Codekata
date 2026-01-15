#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
            answer += ' ';
        else if ('A' <= s[i] && s[i] <= 'Z')
        {
            answer += ((s[i] - 'A' + n) % ('Z' - 'A' + 1)) + 'A';
        } 
        else if ('a' <= s[i] && s[i] <= 'z')
        {
            answer += ((s[i] - 'a' + n) % ('z' - 'a' + 1)) + 'a';
        }
    }
    
    return answer;
}