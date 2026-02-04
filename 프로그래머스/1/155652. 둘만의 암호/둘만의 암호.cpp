#include <string>
#include <vector>
#include <set>

using namespace std;

string solution(string s, string skip, int index) {
    set<char> skipset(skip.begin(), skip.end());
    string answer = "";
    
    for (char c : s) 
    {
        char current = c;
        int count = 0;
        
        while (count < index) 
        {
            current++; // 다음 문자로
            if (current > 'z') current = 'a'; //  z넘어가면 면 a로
            if (!skipset.count(current)) // 개수 세서 없으면
            {
                count++;
            }
        }
        answer += current;
    }
    return answer;
}