#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = -1;
vector<vector<int>> objectiveDungeons;
vector<bool> visited;

void Search(int currentk, int count)
{
    // TODO: 유저가 탐험할 수 있는 '최대' 던전 수 반환
    answer = max(answer, count);
    
    for (int i = 0; i < objectiveDungeons.size(); i++) 
    {
        if (!visited[i]) 
        {
            // 1. 현재 피로도에서 갈 수 있는 던전 하나 방문
            int requiredk = objectiveDungeons[i][0];
            int consumek = objectiveDungeons[i][1];
            
            if (currentk < requiredk)
                continue;
            
            visited[i] = true;
            // 2. 피로도 소모시키고 다음 던전 방문
            Search(currentk - consumek, count + 1);
            
            // 3. 피로도로 인해 던전 탐색 불가의 경우 백트래킹 후 다시 1번부터
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    objectiveDungeons = dungeons;
    visited = vector<bool>(dungeons.size(), false);
    
    Search(k, 0);
    
    return answer;
}