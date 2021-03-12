#include <iostream>
#include <vector>
using namespace std;

void productArray(int A[], int n)
{
    int prod = 1;
    for (int i = 0; i < n; i++)
        prod *= A[i];

    vector<int> P(n);
    for (int i = 0; i < n; i++)
        P[i] = prod / A[i];

    for (int i = 0; i < n; i++)
        cout << P[i] << " ";
}

int main()
{
    int A[] = {10, 3, 5, 6, 2};
    int n = 5;
    productArray(A, n);
}