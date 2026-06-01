#include <string>

using namespace std;

bool visited[11][11][4]; // 좌표계 안의 한 점에서, 4가지 방향을 체크하기 위한 배열까지 선언

// 상, 하, 좌, 우 오프셋
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

int todir(char dir)
{
    int ret;
    
    switch(dir)
    {
        case 'U':
            ret = 0;
            break;
        case 'R':
            ret = 1;
            break;
        case 'D':
            ret = 2;
            break;
        case 'L':
            ret = 3;
            break;
    }
    return ret;
}

// 유효하지 않은 범위 체크
bool isNotValid(int x, int y) { return x < 0 || y < 0 || x > 10 || y > 10; }

// 현재와 반대의 방향 값 반환, (갔던 길의 반대, 왔던 길의 느낌)
int opposite_direction(int dir) { return (dir + 2) % 4; } // + 2 시켜서 뒤집기 / 숫자 초과시 %로 순환

int solution(string dirs) {
    int answer = 0;
    int x = 5, y = 5; // 시작 지점은 5, 5로 지정한다, 배열을 음수로 쓸 수 없으니 원점을 변환
    
    for (auto c : dirs)
    {
        int dir = todir(c);
        int nx = x + dx[dir]; // 증가값으로 좌표 계산
        int ny = y + dy[dir];
        
        if (isNotValid(nx,ny))
        {
            continue;
        }
        
        if (visited[y][x][dir] == false)
        {
            visited[y][x][dir] = true; // 가는길을 방문 체크
            visited[ny][nx][opposite_direction(dir)] = true; // 왔던 길도 체크!!
            answer++; // 횟수는 한번만 증가
        }

        // 현재 좌표를 이동 대상 좌표로 변경
        x = nx;
        y = ny;
    }
    
    return answer;
}