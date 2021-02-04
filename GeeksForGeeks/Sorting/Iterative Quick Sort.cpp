#include <iostream>
#include <stack>
using namespace std;

int partition(int A[], int low, int high)
{
    int pivot = A[high];
    // Last Element as pivot
    int i = low;

    for (int j = low; j < high; j++)
    {
        if (A[j] < pivot)
        {
            swap(A[i], A[j]);
            i++;
        }
    }
    swap(A[i], A[high]);
    return i;
}

struct Interval
{
    int low, high;
};

void quickSort(int A[], int low, int high)
{

    stack<Interval> s;
    Interval i;
    i.low = low;
    i.high = high;
    s.push(i);

    while (!s.empty())
    {
        i = s.top();
        s.pop();
        int pi = partition(A, i.low, i.high);

        if (pi - 1 > i.low)
        {
            Interval k;
            k.low = i.low;
            k.high = pi - 1;
            s.push(k);
        }
        if (pi + 1 < i.high)
        {
            Interval k;
            k.low = pi + 1;
            k.high = i.high;
            s.push(k);
        }
    }
}

int main()
{
    int A[] = {10, 7, 8, 9, 1, 5};
    int n = 6;

    quickSort(A, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}