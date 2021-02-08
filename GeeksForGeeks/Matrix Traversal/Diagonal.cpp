#include <iostream>
#include <vector>
using namespace std;
#define R 3
#define C 5

void Diagonal(int M[R][C])
{
    int i = 0, j = 0;
    while (i < R && j < C)
    {
        int curI = i, curJ = j;
        // Line
        while (curI >= 0 && curJ < C)
            cout << M[curI--][curJ++] << " ";
        if (i + 1 < R)
            i++;
        else
            j++;
    }
}
// Time- O(R*C)
// Line - R+C-1

void DiagonalRecursion(int M[R][C], int i, int j)
{
    if (i + 1 >= R && j + 1 >= C)
        return;

    int curI = i, curJ = j;
    while (curI >= 0 && curJ < C)
        cout << M[curI--][curJ++] << " ";

    int nxtI = i, nxtJ = j;
    if (i + 1 < R)
        nxtI++;
    else
        nxtJ++;
    DiagonalRecursion(M, nxtI, nxtJ);
}

void DiagonalIJ(int M[R][C])
{
    vector<vector<int>> res(R + C - 1);

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            res[i + j].push_back(M[i][j]);

    for (int i = 0; i < res.size(); i++)
        for (int j = res[i].size() - 1; j >= 0; j--)
            cout << res[i][j] << " ";
}
// Time- O()
// Space- O((R+C-1)*max elements in diagonal)

int main()
{

    int M[R][C] = {{1, 2, 3, 4, 5},
                   {6, 7, 8, 9, 10},
                   {11, 12, 13, 14, 15}};

    // Diagonal(M);
    DiagonalRecursion(M, 0, 0);
    // DiagonalIJ(M);
}
