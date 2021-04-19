#include <bits/stdc++.h>
using namespace std;

void SieveOfEratosthenes(int n)
{
    vector<int> A(n + 1);
    for (int i = 0; i <= n; i++)
        A[i] = i;

    vector<int> p;
    vector<bool> touched(n + 1);
    vector<map<int, int>> factors(n + 1);
    for (int i = 2; i <= n; i++)
    {
        if (!touched[i])
        {
            factors[i][i]++;
            A[i] /= i;
            for (int j = 2 * i; j <= n; j += i)
            {
                touched[j] = true;
                while (A[j] % i == 0)
                {
                    factors[j][i]++;
                    A[j] /= i;
                }
            }
        }
    }

    for (int i = 2; i <= n; i++)
        if (!touched[i])
            p.push_back(i);

    for (int i = 0; i < p.size(); i++)
        cout << p[i] << " ";
    cout << "\n";

    for (int i = 0; i <= n; i++)
        cout << A[i] << " ";
    cout << "\n";

    for (int i = 2; i <= n; i++)
    {
        cout << i << "\n";
        for (auto m : factors[i])
        {
            cout << m.first << " " << m.second << " ";
            cout << "\n";
        }
    }
}
// Time- O(n*log(n)*log(log(n)))

int main()
{
    int n = 30;
    SieveOfEratosthenes(n);
    return 0;
}
