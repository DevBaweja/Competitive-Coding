#include <iostream>
#include <stack>
using namespace std;

void reverse(int A[], int n)
{
    for (int i = 0; i < n / 2; i++)
        swap(A[i], A[n - i - 1]);
}
// Time- O(n)
// Space- O(1)

void reverseArray(int A[], int start, int end)
{
    while (start < end)
    {
        int temp = A[start];
        A[start] = A[end];
        A[end] = temp;
        start++;
        end--;
    }
}
// Time O(n)
// Space O(1)

void reverseArrayRecursive(int A[], int start, int end)
{
    if (start > end)
        return;
    int temp = A[start];
    A[start] = A[end];
    A[end] = temp;
    reverseArrayRecursive(A, start + 1, end - 1);
}
// Time O(n)
// Space O(1)

void reverseArrayStack(int A[], int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
        s.push(A[i]);
    for (int i = 0; i < n; i++)
    {
        A[i] = s.top();
        s.pop();
    }
}
// Time- O(n)
// Space- O(n)

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6};
    int n = 6;

    reverse(A, n);
    // reverseArray(A, 0, n - 1);
    // reverseArrayRecursive(A, 0, n - 1);
    // reverseArrayStack(A, n);

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
}