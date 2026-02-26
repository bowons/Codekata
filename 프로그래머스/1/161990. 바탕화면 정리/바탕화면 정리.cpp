#include <string>
#include <vector>
#include <limits>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    pair<int, int> topleft(numeric_limits<int>::max(), numeric_limits<int>::max());
    pair<int, int> bottomright(0, 0);
    
    for (int i = 0; i < wallpaper.size(); i++) 
    {
        for (int j = 0; j < wallpaper[i].length(); j++)
        {
            if (wallpaper[i][j] == '#')
            {
                topleft.first = min(topleft.first, i);
                topleft.second = min(topleft.second, j);
                bottomright.first = max(bottomright.first, i + 1);
                bottomright.second = max(bottomright.second, j + 1);
            }
        }
    }
    
    answer.push_back(topleft.first);
    answer.push_back(topleft.second);
    answer.push_back(bottomright.first);
    answer.push_back(bottomright.second);
    
    return answer;
}