#include <iostream>
#include <stack>
using namespace std;

#define R 4
#define C 5

void spiral(int m, int n, int A[R][C])
{
    // k - Starting Row
    // m - Ending Row
    // l - Starting Column
    // n - Ending Column
    int k = 0, l = 0;
    stack<int> s;
    while (k < m && l < n)
    {
        for (int i = l; i < n; i++)
            s.push(A[k][i]);
        k++;
        for (int i = k; i < m; i++)
            s.push(A[i][n - 1]);
        n--;

        if (k < m)
        {
            for (int i = n - 1; i >= l; i--)
                s.push(A[m - 1][i]);
            m--;
        }
        if (l < n)
        {
            for (int i = m - 1; i >= k; i--)
                s.push(A[i][l]);
            l++;
        }
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}
// Time- O(m*n)
// Space- O(m*n)

int main()
{
    int A[R][C] = {{1, 2, 3, 4, 5},
                   {6, 7, 8, 9, 10},
                   {11, 12, 13, 14, 15},
                   {16, 17, 18, 19, 20}};

    spiral(R, C, A);
    return 0;
}