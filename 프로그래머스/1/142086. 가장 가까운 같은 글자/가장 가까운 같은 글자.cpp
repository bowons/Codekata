#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    for (int i = 0; i < s.length(); i++) 
    {
        string subs = s.substr(0, i);
        auto it = find(subs.rbegin(),subs.rend(), s[i]);
        
        if (it != subs.rend())
        {
            int pos = distance(subs.rbegin(), it) + 1;
            answer.push_back(pos);
        }
        else
        {
            answer.push_back(-1);
        }
    }
    return answer;
}