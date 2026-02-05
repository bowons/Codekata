#include <string>
#include <vector>
#include <set>

using namespace std;

/*
    요구사항: n개 배열 범위에 m만큼 부분 배열을 만들고 section의 모든 숫자를 커버하기
    
    TODO:
    1. section을 set으로 재선언
    2. n개원소 벽 벡터 선언, for루프를 돌며 section 원소에(n배열 기준) + m개 해 길이체크
    
    
*/
int solution(int n, int m, vector<int> section) {
    int answer = 0;
    set<int> sectionset(section.begin(), section.end());
    
    while (!sectionset.empty())
    {
        int start = *sectionset.begin();
        
        for (int i = start; i < start + m; i++)
            sectionset.erase(i);
        
        answer++;
    }
    
    return answer;
}
