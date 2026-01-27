#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    // 요일 배열,  금요일이 1이 되도록 재정렬
    vector<string> days = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};

    // 각 월별 일수 (윤년 기준)
    vector<int> daysInMonth = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    //1월 2월 3월 4월 5월 6월 7월 8월 9월 10월 11월 12월
    
    int date = 0;
    
    for (int i = 0; i < a - 1; i++) // a월 전까지 더해야한다.
    {
        date += daysInMonth[i];
    }
    date += b; // 날짜 b를 더함
    
    string answer = days[date % 7];
    return answer;
}