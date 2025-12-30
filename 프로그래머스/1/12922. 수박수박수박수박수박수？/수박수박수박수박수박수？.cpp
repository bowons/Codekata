#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    vector<string> baksu = {"박", "수"};
    
    for (int i = 1; i <= n; i++)
    {
        answer += baksu[i % 2];
    }
    return answer;
}