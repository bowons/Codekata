#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

// 요구사항
// left와 right까지의 수 i에 대해 약수를 구해 약수의 개수를 반환해야 한다
// 약수의 개수를 받아 짝수라면 더하고 홀수라면 뺀 수를 return하도록 해야한다.

// TODO: 수 i에 대해 약수의 개수를 반환하는 함수
int divisorCount(int num) 
{
    int rtnum = num /2 ;
    int retCount = 0;
    for (int i = 1; i <= rtnum; i++)
    {
        if (num % i == 0) {
            cout << i << endl;
            retCount++;
        }
    }
    retCount++;
    
    return retCount;
}

int solution(int left, int right) {
    int answer = 0;
    
    for (int i = left; i <= right; i++)
    {
        int dCount = divisorCount(i);
        
        answer += dCount % 2 == 0 ? +i : -i;
    }
    
    return answer;
}