#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> numList(10001);

    for (int i = 0; i < n; i++)
    {
        int input;
        std::cin >> input;
        numList[input]++;
    }

    for (int i = 1; i < 10001; i++)
    {
        for (int j = 0; j < numList[i]; j++)
            std::cout << i << '\n';
    }

    return 0;
}