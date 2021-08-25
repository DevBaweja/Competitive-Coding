#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B)
{
    int n = A.size(), m = B.size();
    int j = 0;
    vector<vector<int>> res;
    for (int i = 0; i < n; i++)
    {
        while (j < m && B[j][1] < A[i][0])
            j++;
        while (j < m && A[i][1] >= B[j][0])
        {
            res.push_back({max(A[i][0], B[j][0]), min(A[i][1], B[j][1])});
            if (A[i][1] < B[j][1])
                break;
            j++;
        }
    }
    return res;
}

// Two Pointers
vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B)
{
    int n = A.size(), m = B.size();
    int i = 0, j = 0;
    vector<vector<int>> res;
    while (i < n && j < m)
    {
        if ((B[j][0] <= A[i][0] && A[i][0] <= B[j][1]) || (B[j][1] >= A[i][1] && B[j][0] <= A[i][1]) || (B[j][0] >= A[i][0] && B[j][1] <= A[i][1]))
            res.push_back({max(A[i][0], B[j][0]), min(A[i][1], B[j][1])});

        if (A[i][1] < B[j][1])
            i++;
        else
            j++;
    }
    return res;
}