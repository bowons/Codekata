#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    long long numlong = num;
    
    if (numlong == 1)
        return 0;
    
    int count = 0;
    
    do 
    {
        if (numlong % 2 == 0)
            numlong /= 2;
        else
            numlong = numlong * 3 + 1;    
        
        count++;
        if (count >= 500)
            return -1;
    } while(numlong != 1);
    
    return count;
}