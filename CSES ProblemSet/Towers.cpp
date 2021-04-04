#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
int main()
{
    int n;
    cin >> n;

    vector<ll> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int count = 0, result = 0;
    for (int i = 1; i < n; i++)
    {
        if (A[i] >= A[i - 1])
        {
            count++;
            result = max(result, count);
        }
        else
            count = 0;
    }
    cout << result + 1 << endl;
    return 0;
}
*/

/*
int main()
{
    int n;
    cin >> n;
    vector<ll> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    vector<ll> tower;
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        int j;
        for (j = 0; j < tower.size(); j++)
        {
            if (tower[j] > A[i])
            {
                flag = true;
                break;
            }
        }
        if (!flag)
            tower.push_back(A[i]);
        else
            tower[j] = A[i];
    }
    cout << tower.size() << endl;
}
*/

int main()
{
    int n;
    cin >> n;
    vector<ll> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    vector<ll> tower;
    for (int i = 0; i < n; i++)
    {
        int p = upper_bound(tower.begin(), tower.end(), A[i]) - tower.begin();
        if (p < tower.size())
            tower[p] = A[i];
        else
            tower.push_back(A[i]);
    }
    cout << tower.size() << endl;
}