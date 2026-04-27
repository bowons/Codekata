#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    // 전체 칸 개수 = brown + yellow
    
    // 1. 카펫의 가로 x 세로는 brown + yellow 가 됨 int(20005000)
    int total = brown + yellow;
    
    // 2. 테두리를 한줄 가지려면 무조건 칸이 높이 3칸은 되어야함 (중앙에 하나)
    // 고로 3부터 시작해서 total까지 나눠떨어지는지 보면 width와 height 구할 수 있음
    for (int height = 3; height <= total; height++)
    {
        if (total % height != 0) continue;
        
        int width = total / height;
        
        if (width < height) continue;
        
        int innerWidth = width - 2;
        int innerHeight = height - 2;
        
        if (innerWidth * innerHeight == yellow)
            return {width, height};
    }
    
    return {};
}