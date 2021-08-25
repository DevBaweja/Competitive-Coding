#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;
    vector<int> primes(k);
    for (int i = 0; i < k; i++)
        cin >> primes[i];
    int n;
    cin >> n;

    vector<int> res(n);
    res[0] = 1;
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);
    int i = 0;
    while (i < n)
    {
        int val = pq.top();
        pq.pop();
        if (i == 0 || val != res[i - 1])
        {
            res[i] = val;
            for (int j = 0; j < k; j++)
            {
                pq.push(val * primes[j]);
            }
            i++;
        }
    }
    cout << res[n - 1];
    return 0;
}