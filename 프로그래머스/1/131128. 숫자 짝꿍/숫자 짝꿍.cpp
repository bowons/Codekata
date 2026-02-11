#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    multiset<char> ySet(Y.begin(), Y.end());
    
    vector<char> resultVec;
    
    string answer = "";
    
    for(char x : X) 
    {
        auto it = ySet.find(x);
                
        if (it != ySet.end())
        {
            resultVec.push_back(x);
            ySet.erase(it);
        }
    }
    
    if (resultVec.empty()) return "-1";
    
    sort(resultVec.begin(), resultVec.end(), greater<char>());
    answer.assign(resultVec.begin(), resultVec.end());
    
    if (answer[0] == '0') return "0";
    
    return answer;
}