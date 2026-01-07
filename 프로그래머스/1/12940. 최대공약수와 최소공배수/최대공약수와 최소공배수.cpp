#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    int G = gcd(n,m);
    int L = (n * m) / G;
    
    answer.push_back(G);
    answer.push_back(L);
    return answer;
}