#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (auto& command : commands)
    {
        int i = command[0] - 1;
        int j = command[1] - 1;
        int k = command[2] - 1;
        
        vector<int> temp;
        for (int x = i; x <= j; x++)
        {
            temp.push_back(array[x]);
        }
        sort(temp.begin(), temp.end());
        
        answer.push_back(temp[k]);
    }
    
    return answer;
}