#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    int size = phone_number.size();
    string backnum = phone_number.substr(phone_number.size() - 4);
    
    string answer = "";
    
    for (int i = 0; i < size - 4; i++)
        answer += "*";
    answer += backnum;
    
    return answer;
}