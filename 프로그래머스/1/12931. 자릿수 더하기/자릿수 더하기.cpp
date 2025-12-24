#include <iostream>

using namespace std;

int digit(int number, int index) 
{
    // number를 입력받아 인덱스 i를 기준으로 자릿수 숫자를 추출
    // i = 1: 1 , i = 2: 2, i = 3: 3,
    // 세자리 숫자면 1 * 10 * 10 = 100 -> 123 / 100 = 1 % 10 = 1
    // 두자리 숫자면 1 * 10 = 10 -> 123 / 10 = 12... 12 % 10 = 2
    // 첫자리 숫자.. 1 = 1 -> 123 / 1 = 123 : 123 % 10 = 3
    
    // i를 자리수 만큼 곱하고 i로 몫을 구해 % 10을 한다
    // 덧셈은 교환법칙 때문에 뒤로 더해도 됨
    int digit = 1;
    for (int i = 1; i < index; i++)
        digit *= 10;
    
    number /= digit;
    number %= 10;
    return number;
}

int solution(int n)
{
    int answer = 0;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    for (int i = 1, num = 1; num <= n; i++, num *= 10)
        answer += digit(n, i);
        
    cout << answer << endl;

    return answer;
}