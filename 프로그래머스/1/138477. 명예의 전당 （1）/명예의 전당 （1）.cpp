#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> minPQ;
    
    for (int dailyScore : score)
    {
        minPQ.push(dailyScore);
        
        if (minPQ.size() > k)
        {
            minPQ.pop();
        }
        
        answer.push_back(minPQ.top());
    }
    
    return answer;
}