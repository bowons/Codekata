#include <string>
#include <vector>
#include <regex>

using namespace std;

/*
    요구사항: 영단어 숫자가 들어간 문자열이 주어지고, 이를 온전히 숫자로 변환해야 함
    아이디어: map을 이용?, parseint?
    
    TODO: 
    1. 배열과 인덱스를 이용해 영단어와 숫자를 기록
    2. replace로 교체함
*/

int solution(string s) {
    int answer = 0;
    
    vector<string> wordArr = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    for (int i = 0; i < wordArr.size(); i++)
    {
        auto word = wordArr[i];
        std::regex pattern(word);
        s = std::regex_replace(s, pattern, to_string(i));
        //s.replace(s.find(word), word.length(), to_string(i));    
    }
    answer = stoi(s);
        
    return answer;
}