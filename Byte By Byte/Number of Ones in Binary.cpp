#include <bits/stdc++.h>
using namespace std;

int onesWithoutBitwise(int n)
{
    int count = 0;
    while (n)
    {
        count += (n % 2);
        n /= 2;
    }
    return count;
}

int onesIterative(int n)
{
    int count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
// Time - O(log(n))

int onesRecursive(int n)
{
    if (n == 0)
        return 0;
    else
        return (n & 1) + onesRecursive(n >> 1);
}

int main()
{
    int n;
    cin >> n;
    cout << onesWithoutBitwise(n) << " " << onesIterative(n) << " " << onesRecursive(n);
}