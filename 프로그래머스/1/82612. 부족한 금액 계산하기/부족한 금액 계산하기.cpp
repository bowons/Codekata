using namespace std;

// 요구사항
// 놀이기구는 한 번 이용하는데 price원이 들지만
// n번째 이용부터는 n배가 된다.
// 놀이기구를 count번 사용했을 때 사용된 금액과 현재 money를 뺀 값을 반환해야 한다
// 단, 돈이 충분할 경우에는 0을 반환해야 한다

long long solution(int price, int money, int count)
{
    long long answer = 0;
    
    for (int i = 1; i <= count; i++) 
    {
        answer += price * i;
    }
    
    answer = answer - money;
    
    return answer > 0 ? answer : 0; 
}