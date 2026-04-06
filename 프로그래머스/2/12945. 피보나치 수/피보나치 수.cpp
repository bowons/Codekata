#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
    TODO:
    1. 길이 n만큼의 배열을 선언
    2. f가 0이거나 1일때 1, 배열의 0과 1에는 1 넣어둔다
    3. 배열에서 f(i-1) 와 f(i-2)를 찾아 더해서 새로 집어넣는다
*/ 

int solution(int n) {
    vector<long> fibo(n+1);
    for (int i = 0; i < n+1; i++)
    {
        if (i == 0)
            fibo[i] = 0;
        else if (i == 1)
            fibo[i] = 1;
        else
        {
            fibo[i] = (fibo[i - 1] + fibo[i - 2]) % 1234567;
        }
        //cout << fibo[i];
    }
    
    //int answer = fibo[n] % 1234567;
    
    return fibo[n];
}