#include <bits/stdc++.h>

using namespace std;

/*
    요구사항: 각자 다른 크기의 명함을 모두 수용할 수 있는 지갑을 만들어야 함
    명함은 가로 세로가 주어지며 가로와 세로를 돌릴 수 있다.
    
    1. 예시의 경우 2번 명함을 돌려서 70, 30으로 만들었음
    2. 돌린 경우, wMAX(60 / 70 / 60 / 80) = 80 , hMAX = (50/30/30/40) = 50
    3. wMAX = 80, hMAX = 50, 지갑 크기는 80 * 50이므로 두 MAX 값 곱한것과 일치
    
    TODO: 
    1. 가로와 세로를 뒤집을 기준을 세워, 뒤집을 함수 작성
        - W < H
    2. 가로 세로 배열를 나누어 wMAX와 hMAX를 구함
    3. 둘을 곱하여 answer 반환
*/

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int wMAX = 0;
    int hMAX = 0;
    int wMIN = 10001;
    int hMIN = 10001;
    
    for (int i = 0; i < sizes.size(); i++)
    {
        int W = sizes[i][0];
        int H = sizes[i][1];
        
        if (W < H)
        {
            sizes[i][0] = H;
            sizes[i][1] = W;
            
            W = sizes[i][0];
            H = sizes[i][1];
        }
        
        wMAX = wMAX > W ? wMAX : W;
        hMAX = hMAX > H ? hMAX : H;
    }
    
    answer = wMAX * hMAX;
    return answer;
}