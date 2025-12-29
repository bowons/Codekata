#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare (char a, char b)
{
    return a > b;
}

long long solution(long long n) {
    string s = to_string(n);
    string temp = "";
    
    for (int i = 0; i < s.size(); i++)
    {
        temp.push_back(s[i]);
    }
    sort(temp.begin(), temp.end(), compare);
    
    string res = "";
        
    for (auto c : temp)
    {
        res += c;
    }
        
    long long answer = stoll(res);
    
    return answer;
}