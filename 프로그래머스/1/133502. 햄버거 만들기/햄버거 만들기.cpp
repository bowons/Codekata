#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> stack;
    
    for (int i : ingredient)
    {
        stack.push_back(i);
        
        int n = stack.size();
        if (n >= 4 && 
            stack[n - 4] == 1 && stack[n - 3] == 2 &&
            stack[n - 2] == 3 && stack[n - 1] == 1)
        {
            for (int j = 0; j < 4; j++) stack.pop_back();
            answer++;
        }
    }
    
    return answer;
}