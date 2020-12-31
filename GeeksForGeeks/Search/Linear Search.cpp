#include <iostream>

using namespace std;
// Unsorted Array
int linearSearch(int A[], int n, int el)
{
    for (int i = 0; i < n; i++)
        if (A[i] == el)
            return i;
    return -1;
}
// Time O(n)
// Space O(1)
int main()
{
    int A[] = {2, 3, 4, 10, 40};
    int n = 5;
    int el = 10;
    cout << linearSearch(A, n, el);
}