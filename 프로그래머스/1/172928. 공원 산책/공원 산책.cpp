#include <string>
#include <vector>

using namespace std;

// 핵심 구현 포인트

// 1. 2차원 배열에서 시작 위치 찾기
// 2. 문자열 파싱해 방향과 거리 분리
// 3. 한 칸씩 이동하여 충돌 체크 

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int Height = park.size();
    int Width = park[0].size();
    int Row = 0, Col = 0;
    
    // 1. S 위치 탐색
    for (int i = 0; i < Height; i++)
    {
        for (int j = 0; j < Width; j++)
        {
            if (park[i][j] == 'S')
            {
                Row = i; Col = j;
                break;
            }
        }
    }
    
    // 2. 이동 수행
    for (string route : routes)
    {
        char Direction = route[0];
        char Count = route[2] - '0';
        
        int temp_row = Row;
        int temp_col = Col;
        
        bool bIsPossible = true;
        
        for (int i = 0; i < Count; i++)
        {
            if (Direction == 'N') temp_row--;
            else if (Direction == 'S') temp_row++;
            else if (Direction == 'W') temp_col--;
            else if (Direction == 'E') temp_col++;
            
            // 범위를 벗어나는지 체크한다
            if (temp_row < 0 || temp_row >= Height || temp_col < 0 || temp_col >= Width)
            {
                bIsPossible = false;
                break;
            }
            
            // 장애물이 있는지 체크한다
            if (park[temp_row][temp_col] == 'X')
            {
                bIsPossible = false;
                break;
            }
        }
        
        if (bIsPossible)
        {
            Row = temp_row;
            Col = temp_col;
        }
    }
    
    
    return {Row, Col};
}