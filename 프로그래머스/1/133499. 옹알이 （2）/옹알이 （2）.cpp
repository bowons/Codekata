#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    for (string word : babbling) {
        // 연속 발음 체크용 (불가능한 패턴으로 치환)
        if (word.find("ayaaya") != string::npos ||
            word.find("yeye") != string::npos ||
            word.find("woowoo") != string::npos ||
            word.find("mama") != string::npos) {
            continue;  // 연속 발음 있으면 스킵
        }
        
        // 가능한 발음을 공백으로 치환
        while (word.find("aya") != string::npos) 
            word.replace(word.find("aya"), 3, " ");
        while (word.find("ye") != string::npos) 
            word.replace(word.find("ye"), 2, " ");
        while (word.find("woo") != string::npos) 
            word.replace(word.find("woo"), 3, " ");
        while (word.find("ma") != string::npos) 
            word.replace(word.find("ma"), 2, " ");
        
        // 공백 제거 후 빈 문자열이면 발음 가능
        word.erase(remove(word.begin(), word.end(), ' '), word.end());
        
        if (word.empty()) answer++;
    }
    
    return answer;
}