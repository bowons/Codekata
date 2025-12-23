#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = ((2 + n) * (n / 2)) / 2;
    return answer;
}