#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    map<char, int> mbtimap;
    mbtimap['R'] = 0;
    mbtimap['T'] = 0;
    mbtimap['C'] = 0;
    mbtimap['F'] = 0;
    mbtimap['J'] = 0;
    mbtimap['M'] = 0;
    mbtimap['A'] = 0;
    mbtimap['N'] = 0;
    
    vector<pair<char, char>> orders = {
        {'R', 'T'},
        {'C', 'F'},
        {'J', 'M'},
        {'A', 'N'}
    };
    
    for (int i = 0; i < survey.size(); i++)
    {
        char agree = survey[i][1];
        char disagree = survey[i][0];
        int choice = choices[i];
        
        if (choice < 4)
            mbtimap[disagree] += (4 - choice);
        else if (choice > 4)
            mbtimap[agree] += (choice - 4);
    }
    
    for (auto order : orders)
    {
        char first = order.first;
        char second = order.second;
        
        if (mbtimap[first] >= mbtimap[second])
            answer += first;
        else
            answer += second;
    }
        
    return answer;
}
