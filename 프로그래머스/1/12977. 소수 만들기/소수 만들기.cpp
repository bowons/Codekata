#include <vector>
#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) // n 제곱근 까지만
        if (n % i == 0) return false; //소수 아님
    
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    int n = nums.size();
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++) 
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (isPrime(sum))
                    answer++;
            }
        }
    }
    

    return answer;
}