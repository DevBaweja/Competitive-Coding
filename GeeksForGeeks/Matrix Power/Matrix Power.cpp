#include <bits/stdc++.h>
using namespace std;

int power(int x, int p)
{
    if (p == 0)
        return 1;
    if (p == 1)
        return x;
    int res = power(x, p / 2);
    if (p % 2 == 0)
        return res * res;
    else
        return res * x * res;
}

vector<vector<int>> matrixMultiplication(vector<vector<int>> A, vector<vector<int>> B, int n, int p, int m)
{
    vector<vector<int>> C(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < p; k++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

vector<vector<int>> matrixSelf(vector<vector<int>> A, int n)
{
    vector<vector<int>> B(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                B[i][j] += A[i][k] * A[k][j];
    return B;
}

vector<vector<int>> powerMatrix(vector<vector<int>> A, int n, int p)
{
    if (p == 1)
        return A;
    if (p % 2 == 0)
        return matrixSelf(powerMatrix(A, n, p / 2), n);
    else
        matrixMultiplication(A, matrixSelf(powerMatrix(A, n, p / 2), n), n, n, n);
}

int main()
{
    int n, p;
    cin >> n >> p;
    vector<vector<int>> A(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    vector<vector<int>> B = powerMatrix(A, n, p);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << B[i][j] << " ";
        cout << "\n";
    }
    return 0;
}