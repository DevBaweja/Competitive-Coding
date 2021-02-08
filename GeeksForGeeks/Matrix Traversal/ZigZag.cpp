#include <iostream>
using namespace std;
#define R 3
#define C 5

void ZigZag(int M[R][C])
{
    int current = 0;
    while (current < R)
    {
        if (!current % 2)
            for (int i = 0; i < C; i++)
                cout << M[current][i] << " ";
        else
            for (int i = C - 1; i >= 0; i--)
                cout << M[current][i] << " ";
        current++;
    }
}
// Time- O(n)

void ZigZagRecursion(int M[R][C], int current)
{
    if (current == R)
        return;
    if (!current % 2)
        for (int i = 0; i < C; i++)
            cout << M[current][i] << " ";
    else
        for (int i = C - 1; i >= 0; i--)
            cout << M[current][i] << " ";
    ZigZagRecursion(M, current + 1);
}
// Time- O(n)

int main()
{

    int M[R][C] = {{1, 2, 3, 4, 5},
                   {6, 7, 8, 9, 10},
                   {11, 12, 13, 14, 15}};

    ZigZag(M);
    cout << endl;
    ZigZagRecursion(M, 0);
}