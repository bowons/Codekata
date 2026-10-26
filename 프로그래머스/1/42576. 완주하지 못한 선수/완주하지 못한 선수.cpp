#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    unordered_map<string, int> nameHash;
    
    for (int i = 0; i < participant.size(); i++)
    {
        nameHash[participant[i]]++;
    }
    
    for (int i = 0; i < completion.size(); i++)
    {
        nameHash[completion[i]]--;
        
        if (nameHash[completion[i]] == 0)
            nameHash.erase(completion[i]);
    }
    
    return nameHash.begin()->first;
}