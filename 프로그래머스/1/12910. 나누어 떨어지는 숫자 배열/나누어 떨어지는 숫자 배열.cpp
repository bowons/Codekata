#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer = arr;
    
    answer.erase(remove_if(answer.begin(), answer.end(), 
       [divisor](int x) {
            return x % divisor != 0;
       }
    ), answer.end());
    
    sort (answer.begin(), answer.end());
    
    if (answer.empty()) 
        answer.push_back(-1);
    
    return answer;
}