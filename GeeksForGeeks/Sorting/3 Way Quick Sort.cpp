#include <iostream>
using namespace std;

void quickSort(int A[], int left, int right)
{
    if (left >= right)
        return;

    pair<int, int> p = parition(A, left, right);

    quickSort(A, left, p.second);
    quickSort(A, p.first, right);
}
int main()
{
    int A[] = {4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 4, 9, 1};
    int n = 15;

    quicksort(A, 0, n - 1);

    return 0;
}