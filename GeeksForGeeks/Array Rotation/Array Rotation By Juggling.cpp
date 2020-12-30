#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    // base case
    if (a == b)
        return a;

    if (a > b)
        return gcd(a - b, b);
    if (a < b)
        return gcd(a, b - a);
}

void rotateByJuggling(int A[], int d, int n)
{
    int skip = gcd(n, d);
    for (int i = 0; i < skip; i++)
    {
        int temp = A[i];
        int j = i;
        while (1)
        {
            int k = j + d;
            if (k >= n)
                k = k - n;
            if (k == i)
                break;
            A[j] = A[k];
            j = k;
        }
        A[j] = temp;
    }
}
// Time O(n)
// Space O(1)

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int d = 3;
    int n = 12;

    rotateByJuggling(A, d, n);

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
}
