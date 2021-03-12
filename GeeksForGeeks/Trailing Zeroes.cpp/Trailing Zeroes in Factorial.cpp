#include <iostream>
using namespace std;

int trailingZeros(int n)
{
    int count = 0;
    for (int i = 5; n / i >= 1; i *= 5)
        count += n / i;
    return count;
}
// Time - O(log(n))
// Space - O(1)

int main()
{
    int n = 100;
    cout << trailingZeros(n);
    return 0;
}