#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    
    // 1. 배열의 모든 수를 순회하면서 더하여 나온 값을 계속해서 저장한다
    // 2. 여기서 중복 값을 제거하면 됨
    
    // set을 이용하면 된다
    set<int> sum;
    
    for (int i = 0; i < numbers.size(); i++) 
    {
        for (int j = i + 1; j < numbers.size(); j++) 
        {
            sum.insert(numbers[i] + numbers[j]);
        }
    }
    
    vector<int> answer(sum.begin(), sum.end());
    
    return answer;
}