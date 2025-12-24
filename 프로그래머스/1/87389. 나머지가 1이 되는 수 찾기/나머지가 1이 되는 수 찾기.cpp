#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    // 나머지가 1이 되도록 하는 가장 작은 수 x 구하기
    // 루프를 돌면서 나머지가 1이 될때까지 ++
    
    int answer = 0;
    
    for (int i = 2; i < n; i++) 
    {
        if (n % i == 1)
        {
            answer = i;
            break; // break하여 가장 작은 수를 획득
        }
    }
    
    return answer;
}