#include <iostream>
using namespace std;

typedef long long ll;

int reverse(int n)
{
    int rev = 0;
    while (n != 0)
    {
        int rem = n % 10;
        rev = rev * 10 + rem;
        n /= 10;
    }
    return rev;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << reverse(n) << "\n";
    }
}
