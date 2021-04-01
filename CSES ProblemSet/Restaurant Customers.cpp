#include <bits/stdc++.h>
using namespace std;

/*
int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        A[i] = a;
        B[i] = b;
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int count = 0, result = 0;
    int i = 0, j = 0;
    while (i < n && j < n)
    {
        if (A[i] < B[j])
        {
            i++;
            count++;
        }
        else if (A[i] > B[j])
        {
            j++;
            count--;
        }
        result = max(result, count);
    }
    cout << result << endl;
}
*/
/*
int main()
{
    int n;
    cin >> n;
    set<array<int, 2>> s;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        s.insert({a, 1});
        s.insert({b, -1});
    }

    int count = 0, result = 0;
    for (auto itr = s.begin(); itr != s.end(); itr++)
    {
        count += (*itr)[1];
        result = max(result, count);
    }
    cout << result << endl;
}
*/

int main()
{
    int n;
    cin >> n;
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        s.insert(make_pair(a, 1));
        s.insert(make_pair(b, -1));
    }

    int count = 0, result = 0;
    for (auto itr = s.begin(); itr != s.end(); itr++)
    {
        count += itr->second;
        result = max(result, count);
    }
    cout << result << endl;
}
