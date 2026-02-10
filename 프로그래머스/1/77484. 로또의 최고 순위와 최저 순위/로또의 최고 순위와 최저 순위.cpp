#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> rank = {6,6,5,4,3,2,1};
    vector<int> answer;
    
    set<int> win_lotto(win_nums.begin(), win_nums.end());
    int zeroCount = 0;
    int minHit = 0;
    
    for(int lotto : lottos)
    {
        if (lotto != 0)
        {
            if (win_lotto.count(lotto))
                minHit++;
        }
        else
            zeroCount++;
    }
    
    answer.push_back(rank[minHit + zeroCount]);
    answer.push_back(rank[minHit]);
    
    return answer;
}