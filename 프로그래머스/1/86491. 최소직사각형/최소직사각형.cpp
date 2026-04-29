#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    // 1. 가로와 세로가 전환이 가능하다. 따라서 max값을 구할 때 고려해서 비교를 해야 함
    // 2. 전체 배열을 순회하며 가로와 세로의 max값을 구한다.
    // 3. 가로와 세로의 max를 구하고 난 이후에 곱해서 값을 반환한다.
    int widthMax = 0;
    int heightMax = 0;
    
    for (auto& size : sizes) 
    {
        // 세로와 가로 돌려가며 두번을 비교해본다, 두 가지는 동시에 일어날 수 없다.
        int width = max(size[0], size[1]); // 두 값중 긴 값을 width로 취함
        int height = min(size[0], size[1]); // 두 값중 짧은 값을 height로 취함
        
        widthMax = max(widthMax, width);
        heightMax = max(heightMax, height);
    }
    
    int answer = widthMax * heightMax;
    return answer;
}