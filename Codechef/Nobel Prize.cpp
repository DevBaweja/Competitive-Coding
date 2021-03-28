#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> A(n);

        for (int i = 0; i < n; i++)
            cin >> A[i];

        vector<bool> count(m);
        for (int i = 0; i < n; i++)
            count[A[i] - 1] = true;

        bool result = false;
        for (int i = 0; i < m; i++)
        {
            if (!count[i])
            {
                result = true;
                break;
            }
        }

        if (result)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}