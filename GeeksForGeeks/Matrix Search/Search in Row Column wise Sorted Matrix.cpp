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

int main()
{
    int M[R][C] = {{10, 20, 30, 40, 50},
                   {15, 25, 35, 45, 55},
                   {27, 29, 37, 48, 57},
                   {32, 33, 39, 50, 60}};

    int k = 29;
    pair<int, int> p = searchRowColumn(M, k);
    cout << p.first << " " << p.second;

    return 0;
}
