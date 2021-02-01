#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int repeatingNaive(int A[], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (A[i] == A[j])
                return A[i];
}
// Time- O(n*n)
// Space- O(1)
// Doesn't use fact that there are only two repeating elements in range of 1 to n

int repeatingCount(int A[], int n)
{
    vector<int> count(n - 1);
    for (int i = 0; i < n; i++)
    {
        if (count[A[i]] == 1)
            return A[i];
        count[A[i]]++;
    }
}
// Time- O(n)
// Space- O(n)

int repeatingHashing(int A[], int n)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        if (s.find(A[i]) != s.end())
            return A[i];
        s.insert(A[i]);
    }
}
// Time- O(n)
// Space- O(n)

int repeatingSum(int A[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += A[i];

    return sum - (n * (n - 1) / 2);
}
// Time- O(n)
// Space- O(1)

int repeatingXOR(int A[], int n)
{
    // x^x = 0
    // x^y = y^x

    int n_new = n - 1;
    int R = 0;
    /*
    for (int i = 0; i < n_new; i++)
    {
        R = R ^ (i + 1) ^ A[i];
    }
    R = R ^ A[n_new];
    */
    for (int i = 0; i < n; i++)
        R ^= A[i];
    for (int i = 0; i < n_new; i++)
        R ^= (i + 1);
    return R;
}
// Time- O(n)
// Space- O(1)

int repeatingNegative(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (A[abs(A[i])] < 0)
            return abs(A[i]);
        A[abs(A[i])] = -A[abs(A[i])];
    }
}
// Time- O(n)
// Space- O(1)
// It will modify array but reduce space as compared to count array

int main()
{
    int A[] = {1, 5, 1, 2, 3, 4};
    int n = 6;
    cout << repeatingNaive(A, n) << " " << repeatingCount(A, n) << " " << repeatingHashing(A, n) << " " << repeatingSum(A, n) << " " << repeatingXOR(A, n) << " ";
    cout << repeatingNegative(A, n);
}
