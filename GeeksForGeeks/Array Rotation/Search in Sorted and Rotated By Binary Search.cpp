#include <iostream>

using namespace std;
// Sorted and Rotated

int main()
{
    int A[] = {30, 40, 50, 10, 20};
    int n = 5;
    int el = 10;
    cout << pivotedBinarySearch(A, 0, n - 1, el);
}