#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll atMostK(vector<ll> A, int n, int k)
{
    ll count = 0;
    int left = 0, right = 0;
    map<ll, int> m;
    while (left < n && right < n)
    {
        m[A[right]]++;
        while (m.size() > k && left < n)
        {
            m[A[left]]--;
            if (m[A[left]] == 0)
                m.erase(A[left]);
            left++;
        }

        count += right - left + 1;
        right++;
    }
    return count;
}

ll exactlyK(vector<ll> A, int n, int k)
{
    ll count = 0, result = 0, prefix = 0;
    int left = 0, right = 0;
    map<ll, int> m;
    while (left < n && right < n)
    {
        if (m.find(A[right]) == m.end())
            count++;
        m[A[right]]++;

        if (count > k)
        {
            m[A[left]]--;
            left++;
            count--;
            prefix = 0;
        }
        while (m[A[left]] > 1)
        {
            m[A[left]]--;
            left++;
            prefix++;
        }
        if (count == k)
            result += prefix + 1;

        right++;
    }
    return result;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << atMostK(A, n, k) << endl;
    // Exactly K
    // cout << atMostK(A,n,k) - atMostK(A,n,k-1) << endl;
    // cout << exactlyK(A, n, k) << endl;
    return 0;
}