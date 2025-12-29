#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "Kim";
    auto it = find(seoul.begin(), seoul.end(), answer);
    
    int index = 0;
    if (it != seoul.end())
    {
        index = it - seoul.begin();
    }
        
    return "김서방은 " + to_string(index) +"에 있다";
}