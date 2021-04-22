#include <bits/stdc++.h>
using namespace std;

void zigzagSort(vector<int> &A, int n)
{
    sort(A.begin(), A.end());
    for (int i = 1; i < n - 1; i += 2)
        swap(A[i], A[i + 1]);
}

void zigzagTwoPointer(vector<int> &A, int n)
{
    bool flag = true;
    // true means <
    // false means >
    for (int i = 0; i < n - 1; i++)
    {

        if (flag)
        {
            if (A[i] > A[i + 1])
                swap(A[i], A[i + 1]);
        }
        else
        {
            if (A[i] < A[i + 1])
                swap(A[i], A[i + 1]);
        }
        flag = !flag;
    }
}

int main()
{
    int n = 7;
    vector<int> A{4, 3, 7, 8, 6, 2, 1};

    // zigzagSort(A, n);
    zigzagTwoPointer(A, n);

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
}