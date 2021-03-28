#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int u, v, a, s;
        cin >> u >> v >> a >> s;
        if (v * v >= u * u - 2 * a * s)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}