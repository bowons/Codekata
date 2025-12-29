#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long maxAB = max(a, b), minAB = min(a, b);
    long long n = maxAB - minAB + 1;
    long long answer = (n * (a + b)) / 2;
    return answer;
}