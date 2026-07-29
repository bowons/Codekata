#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    // 1. 각 기능이 완료되기 까지 필요한 날짜 계산
    // day = (100 - progress + speed - 1) / speed
    vector<int> days;
    
    for (int i = 0; i < progresses.size(); i++)
    {
        int remain = 100 - progresses[i];
        int day = (remain + speeds[i] - 1) / speeds[i];
        
        days.push_back(day);
    }
    
    // 2. 첫 번째 기능의 완료일을 기준일로 설정
    int standard = days[0];
    int count = 1;
    
        // 3, 다음 기능들 순회
    // 완료일 <= 기준일 -> 같은 배포 그룹 Count 증가
    // 완료일 > 기준일 -> 새로운 배포 그룹 Count를 Answer에 추가, 기준일 갱신, count = 1
    for (int i = 1; i < days.size(); i++)
    {
        if (days[i] <= standard)
        {
            count++;
        } 
        else
        {
            answer.push_back(count);
            standard = days[i];
            count = 1;
        }
    }
    
    // 4. 마지막 그룹 count answer에 저장
    answer.push_back(count);
    
    return answer;
}