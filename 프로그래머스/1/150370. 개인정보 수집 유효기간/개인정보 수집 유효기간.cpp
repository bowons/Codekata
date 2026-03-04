#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 1. 날짜 환산 - (Y + 12 * 28) + (M * 28) + D -> 모든 날짜를 일수로
// 2. terms 배열을 순회하며 각 약관(A~Z)의 유효기간을 일수로 변환해 해시맵 저장
// 3. 각 개인정보의 수집 일자도 일수로 변환한 뒤, 약관에 따른 유효기간(일수)을 더함, 
//    이 값이 오늘 날짜의 일수보다 작거나 같으면 파기 대상

// 모든 날짜를 일수 변환 함수
int DateToDays(const string& date)
{
    int year = stoi(date.substr(0,4));
    int month = stoi(date.substr(5,2));
    int day = stoi(date.substr(8,2));
    
    return (year * 12 * 28) + (month * 28) + day;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    // 1. 오늘 날짜 일수로 변환
    int todayDays = DateToDays(today);
    
    // 2. 약관 정보 맵 저장
    unordered_map<char, int> termMap;
    for (const string& term : terms)
    {
        char type = term[0];
        int months = stoi(term.substr(2));
        termMap[type] = months * 28; // 달 수 -> 일 수
    }
    
    // 3. 개인정보 만료 여부 확인
    for (int i = 0; i < privacies.size(); ++i) {
        // 날짜와 약관 종류 분리
        string datePart = privacies[i].substr(0, 10);
        char type = privacies[i][11];
        
        // 수집 일자를 일수로 변환하고 유효기간을 더함
        int collectedDays = DateToDays(datePart);
        int expirationDays = collectedDays + termMap[type];
        
        // 만료일이 오늘 날짜보다 작거나 같으면 파기 대상 (1번부터 시작하므로 i + 1)
        if (expirationDays <= todayDays) {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}