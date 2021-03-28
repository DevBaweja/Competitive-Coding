#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Enable Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++)
            cin >> A[i];

        int total = 1;
        int minimum = A[0];
        for (int i = 1; i < n; i++)
        {
            if (A[i] <= minimum)
            {
                minimum = min(minimum, A[i]);
                total++;
            }
        }
        cout << total << "\n";
    }
    return 0;
}