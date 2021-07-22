#include <bits/stdc++.h>
using namespace std;

vector<int> leftRotate(vector<int> input, int size, int t)
{
    while (t--)
    {
        int temp = input[0];
        for (int i = 0; i < size - 1; i++)
            input[i] = input[i + 1];
        input[size - 1] = temp;
    }
    return input;
}

vector<int> rightRotate(vector<int> input, int size, int t)
{
    while (t--)
    {
        int temp = input[size - 1];
        for (int i = size - 1; i > 0; i--)
            input[i] = input[i - 1];
        input[0] = temp;
    }
    return input;
}

bool isEqual(vector<int> a, vector<int> b, int n)
{
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            return false;
    return true;
}

int isSuperSimilar(int n, int m, vector<vector<int>> &mat, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            vector<int> lr = leftRotate(mat[i], m, x);
            if (!isEqual(lr, mat[i], m))
                return false;
        }
        else
        {
            vector<int> rr = rightRotate(mat[i], m, x);
            if (!isEqual(rr, mat[i], m))
                return false;
        }
    }
    return true;
}