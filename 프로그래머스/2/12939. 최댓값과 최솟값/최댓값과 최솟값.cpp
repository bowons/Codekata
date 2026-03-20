#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
/*
    TODO: stringstream으로 문자열 쪼개서, 최대 최소 구하면 된다.
*/

string solution(string s) {
    std::stringstream ss(s);
    
    vector<int> numVec;
    
    for (auto& c : s)
    {
        int toInt;
        ss >> toInt;
        
        numVec.push_back(toInt);
    }
    
    std::stringstream res;
    res << *min_element(numVec.begin(), numVec.end()) 
        << " " << *max_element(numVec.begin(), numVec.end());
    
    return res.str();
}