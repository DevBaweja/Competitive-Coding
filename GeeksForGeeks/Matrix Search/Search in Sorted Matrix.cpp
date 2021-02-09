#include <iostream>
using namespace std;
#define R 3
#define C 4

pair<int, int> searchSortedMatrixNaive(int M[R][C], int k)
{
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (M[i][j] == k)
                return make_pair(i, j);
    return make_pair(-1, -1);
}

int binarySearch(int A[], int k)
{
    int low = 0, high = C - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (A[mid] == k)
            return mid;
        if (A[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

pair<int, int> searchSortedMatrix(int M[R][C], int k)
{
    int low = 0, high = R - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (k >= M[mid][0] && k <= M[mid][C - 1])
        {
            int col = binarySearch(M[mid], k);
            if (col == -1)
                return make_pair(-1, -1);
            return make_pair(mid, col);
        }
        if (M[mid][0] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return make_pair(-1, -1);
}
// Binary Search in R then C
// Time- O(log(n)*log(m))

int main()
{
    int M[R][C] = {{1, 3, 5, 7},
                   {10, 11, 16, 20},
                   {23, 30, 34, 50}};
    int k = 16;
    pair<int, int> p = searchSortedMatrix(M, k);
    cout << p.first << " " << p.second;
}