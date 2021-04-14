#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/*
int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int count = 0;

    int low = 0, high = 0;
    while (low < n && high < n)
    {
        int sum = 0;
        for (int k = low; k <= high; k++)
            sum += A[k];
        if (sum == x)
            count++;
        if (sum > x)
            low++;
        else
            high++;
    }
    cout << count << endl;
    return 0;
}
*/

/*
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    int low = 0, high = 0;
    int sum = 0, count = 0;
    while (low < n && high < n)
    {
    }

    cout << count << endl;
    return 0;
}
*/

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    map<ll, int> m;
    m[0]++;
    // 1+1+1
    // [2,4,1,2,7]
    // m[0] = 1
    // m[2] = 1
    // m[6] = 1
    // m[7] = 1
    // m[9] = 1
    // m[16] = 1

    // m[2] = 1
    // m[6-7] = m[-1] = 0
    // m[2-7] m[-5] = 0
    ll sum = 0,
       count = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        count += m[sum - x];
        m[sum]++;
    }
    cout << count << endl;
}