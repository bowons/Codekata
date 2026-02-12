#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> student(n + 1, 1);

    for (int rstudent : reserve)
        student[rstudent]++;
    
    for (int lstudent : lost)
        student[lstudent]--;
    
    for (int i = 1; i <= n; i++)
    {
        if (student[i] == 0)
        {
            int prev = i - 1;
            int next = i + 1;
            if (prev != 0)                
            {
                if (student[prev] > 1)
                {
                    student[prev]--;
                    student[i]++;
                    continue;
                }
            }   
            
            if (next != n + 1)
            {
                if (student[next] > 1)
                {
                    student[next]--;
                    student[i]++;
                }
            }
        }
    }
    
    int answer = count_if(student.begin() + 1, student.end(), [](int x) { return x >= 1; });
    return answer;
}