#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, y, x;
        cin >> a >> y >> x;
        if (y <= a)
            cout << x * y;
        else
            cout << 1 + a * x;
        cout << "\n";
    }
    return 0;
}