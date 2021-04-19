#include <bits/stdc++.h>
using namespace std;

/*
vector<bool> SieveOfEratosthenes(int n)
{
    vector<bool> p(n + 1, true);
    for (int i = 2; i * i <= n; i++)
    {
        if (p[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                p[j] = false;
            }
        }
    }
    return p;
}
*/
// Time - O(n*log(log(n)))

vector<int> SieveOfEratosthenes(int n)
{
    vector<int> p;
    vector<bool> touched(n + 1);
    for (int i = 2; i * i <= n; i++)
    {
        if (!touched[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                touched[j] = true;
            }
        }
    }
    for (int i = 2; i <= n; i++)
        if (!touched[i])
            p.push_back(i);
    return p;
}

int main()
{
    int n = 30;
    /*
    vector<bool> p = SieveOfEratosthenes(n);
    for (int i = 2; i <= n; i++)
        if (p[i])
            cout << i << " ";
            */
    vector<int> p = SieveOfEratosthenes(n);
    for (int i = 0; i < p.size(); i++)
        cout << p[i] << " ";
    return 0;
}
