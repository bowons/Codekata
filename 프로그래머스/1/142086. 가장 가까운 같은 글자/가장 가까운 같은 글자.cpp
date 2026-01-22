#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<char, int> lastPos;  // 각 문자의 마지막 위치 저장

    for (int i = 0; i < s.length(); i++) {
        if (lastPos.find(s[i]) != lastPos.end()) {
            answer.push_back(i - lastPos[s[i]]);
        } else {
            answer.push_back(-1);
        }
        lastPos[s[i]] = i;  // 현재 위치 갱신
    }

    return answer;
}