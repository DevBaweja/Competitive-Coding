#include <iostream>
using namespace std;
#define R 4
#define C 5

pair<int, int> searchRowColumn(int M[R][C], int k)
{
    int smallest = M[0][0], largest = M[R - 1][C - 1];
    if (k < smallest || k > largest)
        return make_pair(-1, -1);

    int i = 0, j = C - 1;
    while (i < R && j >= 0)
    {
        if (M[i][j] == k)
            return make_pair(i, j);
        if (M[i][j] > k)
            j--;
        else
            i++;
    }
    return make_pair(-1, -1);
}
// Time- O(m+n)
// Space- O(1)

pair<int, int> searchRowColumnRecursive(int M[R][C], int fromRow, int toRow, int fromCol, int toCol, int k)
{
    int i = (toRow + fromRow) / 2;
    int j = (toCol + fromCol) / 2;
    if (M[i][j] == k)
        return make_pair(i, j);

    if (i != toRow && j != fromCol)
        searchRowColumnRecursive(M, fromRow, i, j, toCol, k);

    // Special 1*2 matrix
    // if (fromRow == toRow && fromCol + 1 == toCol)
    //     if (M[fromRow][toCol] == k)
    //         return make_pair(fromRow, toCol);

    if (M[i][j] < k)
    {
        if (i + 1 <= toRow)
            searchRowColumnRecursive(M, i + 1, toRow, fromCol, toCol, k);
    }
    else
    {
        if (j - 1 >= fromCol)
            searchRowColumnRecursive(M, fromRow, toRow, fromCol, j - 1, k);
    }
}

int main()
{
    int M[R][C] = {{10, 20, 30, 40, 50},
                   {15, 25, 35, 45, 55},
                   {27, 29, 37, 48, 57},
                   {32, 33, 39, 50, 60}};

    int k = 29;
    // pair<int, int> p = searchRowColumn(M, k);
    pair<int, int> p = searchRowColumnRecursive(M, 0, R - 1, 0, C - 1, k);
    cout << p.first << " " << p.second;

    return 0;
}
