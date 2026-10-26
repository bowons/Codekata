#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    
    vector<int> answer(2, 0);
    unordered_set<string> usedWords;
    
    // 모든 단어 input
    usedWords.insert(words[0]);
    for (int i = 1; i < words.size(); i++)
    {
        bool result = !usedWords.insert(words[i]).second || words[i].front() != words[i - 1].back();
        
        if (result)
        {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            return answer;
        }
            
    }
    
    return answer;
}