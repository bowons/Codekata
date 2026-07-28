#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int a, b, c;

    cin >> a >> b >> c;

    int sum = (a + b + c), avg = sum / 3;
    cout << sum << endl;
    cout << avg << endl;
    cout << sum - avg << endl;
    return 0;
}