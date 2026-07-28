#include <stack>
#include <string>
#include <vector>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    // TODO
    // 1. 이전 행과 다음 행의 Up down 정보가 있는 배열 선언
    vector<int> up;
    vector<int> down;
    
    for (int i = 0; i < n + 2; i++)
    {
        up.push_back(i - 1);
        down.push_back(i + 1);
    }
    
    k++; // 0행의 up과 마지막 행의 Down 임시공간 2개 때문에 k는 한칸 증가
    
    // 2. 삭제 - 다음 행의 Up을 이전 행에 연결 / 이전 행의 Down을 다음 행에 연결
    stack<int> deleted;
    
    for (int i = 0; i < cmd.size(); i++)    
    {
        if (cmd[i][0] == 'C')
        {
            deleted.push(k);
            int prevIndex = up[k];
            int nextIndex = down[k];
            down[prevIndex] = nextIndex;
            up[nextIndex] = prevIndex;
            
            if (down[k] == n + 1) // 다음 행이 없을 경우
                k = up[k];
            else
                k = down[k];
        }
        // 3. Z - Ctrl Z처럼, Stack에서 최신 이력을 하나 Pop
        else if (cmd[i][0] == 'Z')
        {
            int removed = deleted.top();

            int prevIndexRecover = up[removed];
            int nextIndexRecover = down[removed];
            down[prevIndexRecover] = removed;
            up[nextIndexRecover] = removed;

            deleted.pop();
        }
        // 위 아래 이동    
        else
        {
            int sz = stoi(cmd[i].substr(2));

            if (cmd[i][0] == 'U')
            {
                for (int j = 0; j < sz; j++)
                {
                    k = up[k];
                }
            }
            else if (cmd[i][0] == 'D')
            {
                for (int j = 0; j < sz; j++)
                {
                    k = down[k];
                }
            }
        }
    }
    
    
    string answer;
    // 삭제된 행 위치에는 x를 반환
    
    answer.append(n, 'O');
    
    while(!deleted.empty())
    {
        answer[deleted.top() - 1] = 'X';
        deleted.pop();
    }
    
    return answer;
}