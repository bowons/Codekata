#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int p_len = p.length();
    
    long long p_num = 0;
    
    for (int i = 0; i < p_len; i++)
    {
        p_num = p_num * 10 + (p[i] - '0'); // 10씩 곱하며 문자.. 자릿수 추가해줌
    }
    
    // 원 숫자 t에서 비교 숫자 뽑아서 비교함
    for (int i = 0; i <= t.length() - p_len; i++) 
    {
        long long t_num = 0;
        for (int j = 0; j < p_len; j++) 
        {
            t_num = t_num * 10 + (t[i + j] - '0'); // 이전 예제의 3중 포문을 여기서는 문자열에 i + j를 해서 접근
        }

        if (t_num <= p_num)
        {
            answer++;
        }
    }
    
    return answer;
}