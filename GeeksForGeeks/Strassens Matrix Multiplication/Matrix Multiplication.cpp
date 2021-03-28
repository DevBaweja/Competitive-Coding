#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrixMultiplicationSqaure(vector<vector<int>> A, vector<vector<int>> B, int n)
{
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

vector<vector<int>> matrixMultiplicationRect(vector<vector<int>> A, vector<vector<int>> B, int n, int p, int q)
{
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < p; i++)
        for (int j = 0; j < q; j++)
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}
// Time - O(npq) = O(n^3)

int main()
{
    int n = 2;
    vector<vector<int>> A = {{1, 2}, {3, 4}};
    vector<vector<int>> B = {{1, 2}, {3, 4}};
    int p = 2, q = 2;
    // Matrix (p*n) and (n*q)

    // vector<vector<int>> C = matrixMultiplicationSqaure(A, B, n);
    vector<vector<int>> C = matrixMultiplicationRect(A, B, n, p, q);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << C[i][j] << " ";
        cout << "\n";
    }

    return 0;
}