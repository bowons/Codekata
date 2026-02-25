#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(string s) {
    vector<int> nums;
    stringstream ss(s);
    string temp;
    
    // 공백으로 분리해서 정수로 변환
    while (ss >> temp) {
        nums.push_back(stoi(temp));
    }
    
    int minVal = *min_element(nums.begin(), nums.end());
    int maxVal = *max_element(nums.begin(), nums.end());
    
    string answer = to_string(minVal) + " " + to_string(maxVal);
    return answer;
}