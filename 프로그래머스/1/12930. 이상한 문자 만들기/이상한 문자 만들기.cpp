#include <string>
#include <vector>
#include <cctype> // to upper to lower

using namespace std;

string solution(string s) {
    string answer = "";
    int idx = 0; // 단어 내 인덱스

    for (char c : s) {
        if (c == ' ') {
            // 공백이면 그대로 추가하고 인덱스 초기화
            answer += c;
            idx = 0;
        } else {
            if (idx % 2 == 0) {
                // 짝수 인덱스  대문자
                answer += toupper(c);
            } else {
                // 홀수 인덱스  소문자
                answer += tolower(c);
            }
            idx++;
        }
    }

    return answer;
}