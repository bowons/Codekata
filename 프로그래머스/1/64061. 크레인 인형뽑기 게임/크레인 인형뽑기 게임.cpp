#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    // 1. 보드 열 크기만큼 스택 생성
    stack<int> lanes[board[0].size()];
    
    // 2. 보드 가장 밑 행부터 위로 올라가며 순회
    for (int i = board.size() - 1; i >= 0; --i)
    {
        for (int j = 0; j < board[0].size(); ++j)
        {
            // 3. 블럭이 있을 경우에 푸쉬, 총 5개의 lane 스택 생성 완
            if (board[i][j] > 0)
                lanes[j].push(board[i][j]);
        }    
    }
    
    // 보드판에서 꺼낸 인형을 담을 버킷, 사라진 인형의 개수를 저장할 answer
    stack<int> bucket;
    int answer = 0;
    
    for (int m : moves)
    {
        // 4. 만약 lane에 블럭이 있다면
        if (lanes[m - 1].size())
        {
            int doll = lanes[m - 1].top();
            lanes[m - 1].pop();
         
            // 5. Bucket에 인형이 있고 가장 최근 인형과 같은지 확인, 같다면 둘다 답에 추가
            if (bucket.size() && bucket.top() == doll)
            {
                bucket.pop();
                answer += 2;
            } else
            {
                bucket.push(doll);
            }
        }
        
    }
    
    return answer;
}