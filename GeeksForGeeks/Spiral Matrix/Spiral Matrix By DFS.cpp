#include <iostream>
#include <vector>
using namespace std;

#define R 3
#define C 6

bool isInBounds(int i, int j)
{
    return i >= 0 && i < R && j >= 0 && j < C;
}

bool isBlocked(int A[R][C], int i, int j)
{
    if (!isInBounds(i, j) || A[i][j] == -1)
        return true;
    return false;
}

void spiralDFS(int A[R][C], int i, int j, int dir, vector<int> &res)
{
    if (isBlocked(A, i, j))
        return;

    res.push_back(A[i][j]);
    A[i][j] = -1;

    bool allBlocked = true;

    for (int k = -1; k <= 1; k += 2)
        allBlocked = allBlocked && isBlocked(A, i + k, j) && isBlocked(A, i, j + k);

    if (allBlocked)
        return;
    int nxt_i = i;
    int nxt_j = j;
    int nxt_dir = dir;

    if (dir == 0)
    {
        if (!isBlocked(A, i, j + 1))
            nxt_j++;
        else
        {
            dir = 1;
            nxt_i++;
        }
    }
    else if (dir == 1)
    {
        if (!isBlocked(A, i + 1, j))
            nxt_i++;
        else
        {
            dir = 2;
            nxt_j--;
        }
    }
    else if (dir == 2)
    {
        if (!isBlocked(A, i, j - 1))
            nxt_j--;
        else
        {
            dir = 3;
            nxt_i--;
        }
    }
    else if (dir == 3)
    {
        if (!isBlocked(A, i - 1, j))
            nxt_i--;
        else
        {
            dir = 0;
            nxt_j++;
        }
    }
    spiralDFS(A, nxt_i, nxt_j, dir, res);
}

vector<int> spiral(int A[R][C])
{
    vector<int> res;
    spiralDFS(A, 0, 0, 0, res);
    return res;
}
// Time- O(m*n)
// Space- O(1)

int main()
{
    int A[R][C] = {{1, 2, 3, 4, 5, 6},
                   {7, 8, 9, 10, 11, 12},
                   {13, 14, 15, 16, 17, 18}};

    vector<int> res = spiral(A);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}