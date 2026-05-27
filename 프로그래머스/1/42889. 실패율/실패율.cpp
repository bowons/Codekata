#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> remains(N + 2, 0); // 스테이지에 도달했으나 클리어하지 못한 플레이어
    
    vector<int> reached(N + 3, 0); // 스테이지에 도달한 플레이어 수
    vector<double> fail_ratio(N + 1); // 스테이지 실패율
    vector<int> ret(N);
    
    // remains, ratio, fail_ratio 구하기
    for (int challenging_stage : stages)
    {
        ++remains[challenging_stage];
    }
    
    for (int i{N + 1}; i > 0; i--)
    {
        reached[i] = reached[i + 1] + remains[i];
    }
    
    for (int i{1}; i <= N; i++)
    {
        fail_ratio[i] = ((reached[i] == 0) ? 0.0f : 1.0f * remains[i] / reached[i]);
    }
    
    for (int i{1}; i <= N; i++)
    {
        ret[i - 1] = i;
    }
    
    sort(ret.begin(), ret.end(), [&fail_ratio](int& lhs, int& rhs){
        if (fail_ratio[lhs] == fail_ratio[rhs]) return lhs < rhs;
        return fail_ratio[lhs] > fail_ratio[rhs];
    });
    
    return ret;
}