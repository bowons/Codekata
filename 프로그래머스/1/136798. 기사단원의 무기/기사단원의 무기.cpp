#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void pushDivisors(int num, vector<int>& numVec) 
{
    int count = 0;
    for (int i = 1; i * i <= num; i++)
    {
        if (num % i == 0) 
        {
            count++;
            if (i * i != num) count++; // 완전 제곱수가 아닌 경우 한번 더 count ++; (쌍 추가)
        }
    }
     numVec.push_back(count);
}

int solution(int number, int limit, int power) {
    int answer = 0;
    
    vector<int> numberVec;
    for (int i = 1; i <= number; i++)
        pushDivisors(i, numberVec);
    
    replace_if(numberVec.begin(), numberVec.end(), [limit](int x) { return x > limit; }, power);
    answer = accumulate(numberVec.begin(), numberVec.end(), 0);
    
    return answer;
}