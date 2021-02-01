#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std;

pair<int, int> repeatingNaive(int A[], int n)
{
    pair<int, int> p;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (A[i] == A[j])
                if (!p.first)
                    p.first = A[i];
                else
                {
                    p.second = A[j];
                    break;
                }
    return p;
}
// Time- O(n*n)
// Space- O(1)
// Doesn't use fact that there are only two repeating elements in range of 1 to n

pair<int, int> repeatingHashing(int A[], int n)
{
    unordered_set<int> s;
    pair<int, int> p;
    for (int i = 0; i < n; i++)
    {
        if (s.find(A[i]) != s.end())
        {
            if (!p.first)
                p.first = A[i];
            else
            {
                p.second = A[i];
                break;
            }
        }
        s.insert(A[i]);
    }
    return p;
}
// Time- O(n)
// Space- O(n)

pair<int, int> repeatingCount(int A[], int n)
{
    pair<int, int> p;
    vector<int> count(n - 2);
    for (int i = 0; i < n; i++)
    {
        if (count[A[i]] == 1)
        {
            if (!p.first)
                p.first = A[i];
            else
            {
                p.second = A[i];
                break;
            }
        }
        count[A[i]]++;
    }

    return p;
}
// Time- O(n)
// Space- O(n)

int fact(int n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

pair<int, int> repeatingEquation(int A[], int n)
{
    int n_calc = n - 2;
    int S_calc = (n_calc) * (n_calc - 1) / 2;
    int P_calc = fact(n_calc);

    int S = 0;
    int P = 1;
    for (int i = 0; i < n; i++)
    {
        S += A[i];
        P *= A[i];
    }

    S = S - S_calc; // x+y
    P = P / P_calc; // x*y

    int D = sqrt(S * S - 4 * P);

    pair<int, int> p;
    p.first = (S + D) / 2;
    p.second = (S - D) / 2;
    return p;
}
// Time- O(n)
// Space- O(1)

pair<int, int> repeatingNegative(int A[], int n)
{
    pair<int, int> p;
    for (int i = 0; i < n; i++)
    {
        if (A[abs(A[i])] < 0)
        {
            if (!p.first)
                p.first = abs(A[i]);
            else
            {
                p.second = abs(A[i]);
                break;
            }
        }
        A[abs(A[i])] = -A[abs(A[i])];
    }
    return p;
}
// Time- O(n)
// Space- O(1)
// It will modify array but reduce space as compared to count array

int main()
{
    int A[] = {4, 2, 4, 5, 2, 3, 1};
    int n = 7;
    pair<int, int> p = repeatingNegative(A, n);
    cout << p.first << " " << p.second;
}
