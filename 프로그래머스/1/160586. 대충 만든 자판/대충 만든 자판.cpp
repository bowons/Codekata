#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    // 최소 누름 횟수 저장 map
    map<char, int> minPress;
    
    for (string key : keymap)
    {
        for (int i = 0; i < key.size(); i++)
        {
            char c = key[i];
            int press = i + 1;
            
            if (minPress.find(c) == minPress.end())
            {
                minPress[c] = press;
            }
            else
            { // 있다면 갱신
                minPress[c] = min(minPress[c], press);
            }
        }
    }
    
    for (string target : targets) {
        int total = 0;
        bool possible = true;
        
        for (char c : target) {
            if (minPress.find(c) == minPress.end()) {
                possible = false;  // 해당 문자 없음
                break;
            }
            total += minPress[c];
        }
        
        answer.push_back(possible ? total : -1);
    }
    
    return answer;
}