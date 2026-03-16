#include <string>
#include <vector>
#include <map>
#include <sstream>

// 핵심은 방향을 매핑하는 것

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    map<char, pair<int, int>> dir = 
    {
        { 'N', {0, -1} },
        { 'S', {0, +1} },
        { 'W', {-1, 0} },
        { 'E', {+1, 0} }
    };
    
    int height = park.size();
    int width = park[0].size();
    int curX, curY;
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (park[i][j] == 'S')
            {
                curX = j;
                curY = i;
            }
        }
    }
    
    for(string route : routes)    
    {
        stringstream ss(route);
        char op;
        int n;
        ss >> op >> n;
        
        int dx = dir[op].first;
        int dy = dir[op].second;
        
        int nextX = curX;
        int nextY = curY;
        bool isOk = true;
        
        for(int i = 0; i < n; i++) {
            nextX += dx;
            nextY += dy;
            
            if (nextX < 0 || nextY < 0 || nextX >= width || nextY >= height || park[nextY][nextX] == 'X')
            {
                isOk = false;
                break;
            }
        }
        
        if (isOk)
        {
            curX = nextX;
            curY = nextY;
        }
    }
    
    return {curY, curX};
}