#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> cMap;
    
    for (auto& part : clothes)
        cMap[part[1]]++; // 착용부위  개수 + 1
    
    int answer = 1;
    for (auto& part : cMap)
        answer *= (part.second + 1);
    
    return answer - 1; // 하나 이상은 입는다
}