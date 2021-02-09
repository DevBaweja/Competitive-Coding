#include <iostream>
using namespace std;

int reverseDigits(int digit)
{
    int revDigit = 0;
    while (digit > 0)
    {
        revDigit = revDigit * 10 + digit % 10;
        digit /= 10;
    }
    return revDigit;
}
// Time- O(log(n))

int reverseDigitsRecursive(int digit)
{
    static int revDigits = 0;
    static int basePos = 1;
    if (digit > 0)
    {
        reverseDigitsRecursive(digit / 10);
        revDigits += (digit % 10) * basePos;
        basePos *= 10;
    }
    return revDigits;
}
// Time- O(log(n))

int main()
{
    int num = 4562;
    cout << reverseDigitsRecursive(num);
    return 0;
}
