#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    
    int prevDat = 0;
    
    for (int i = 0; i < n; i++) 
    {
        prevDat = x + prevDat;
        answer.push_back(prevDat);
    }
    
    return answer;
}