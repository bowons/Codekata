#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    
    unordered_map<string,int> playerMap;
    for (int i = 0; i < players.size(); i++)
    {
        playerMap[players[i]] = i;
    }
    
    for (const string& calling : callings)
    {
        int currentRank = playerMap[calling];
        
        int frontRank = currentRank - 1;
        string frontPlayer = players[frontRank];
        
        players[frontRank] = calling;
        players[currentRank] = frontPlayer;
        
        playerMap[calling] = frontRank;
        playerMap[frontPlayer] = currentRank;
    }
    
    return players;
}