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
        ll A[n];
        for (int i = 0; i < n; i++)
            cin >> A[i];

        ll result = A[n - 1];
        for (int i = n - 2; i >= 0; i--)
            result += max(0ll, A[i] - A[i + 1] + 1);

        cout << result << "\n";
    }
    return 0;
}