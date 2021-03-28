#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll x, result = 0;
        cin >> x;
        for (int i = 0; i < n; i++)
        {
            ll s, r;
            cin >> s >> r;
            if (s <= x)
                result = max(result, r);
        }
        cout << result << "\n";
    }
    return 0;
}