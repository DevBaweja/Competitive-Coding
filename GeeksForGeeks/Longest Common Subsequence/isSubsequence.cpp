#include <bits/stdc++.h>
using namespace std;

bool isSubSequence(string A, string B)
{
    int n = A.size();
    int m = B.size();
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (A[i] == B[j])
            i++;
        j++;
    }
    return i == n;
}

int main()
{
    string A = "AXY",
           B = "YADXCP";
    cout << isSubSequence(A, B);
    return 0;
}