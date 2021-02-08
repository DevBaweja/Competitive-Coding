#include <iostream>
using namespace std;

bool reverseDigits(int digit)
{
    int temp = digit;
    int revDigit = 0;
    while (temp > 0)
    {
        revDigit = revDigit * 10 + temp % 10;
        temp /= 10;
    }
    return revDigit == digit;
}
// Time- O(log(n))

int main()
{
    int num = 1331;
    cout << reverseDigits(num);
    return 0;
}
