#include <iostream>
using namespace std;

class MinHeap
{
    int *H;
    int size;

public:
    MinHeap(int A[], int n);
    void MinHeapify(int i);
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * (i + 1); }
    int extractMin();
    void insertKey(int k);
    int decreaseKey(int i, int k);
    int deleteKey(int i);
};

MinHeap::MinHeap(int A[], int n)
{
    H = A;
    size = n;
    int start = (n / 2) - 1;
    for (int i = start; i >= 0; i--)
        MinHeapify(i);
}

void MinHeap::MinHeapify(int i)
{
    int smallest = i;
    int l = left(i);
    int r = right(i);
    // Top Down

    if (l < size && H[l] < H[smallest])
        smallest = l;
    if (r < size && H[r] < H[smallest])
        smallest = r;

    if (i != smallest)
    {
        swap(H[i], H[smallest]);
        MinHeapify(smallest);
    }
}
// Heapify single node O(log(n))
// No leaf node need heapify
// Last non leaf = Parent of last leaf (n-1) = ((n-1)-1)/2 = (n/2)-1

// getMin- O(1)
// extractMin- O(log(n))
// insert- O(log(n))
// delete- O(log(n))

int MinHeap::extractMin()
{
    int root = H[0];
    H[0] = H[size - 1];
    size--;
    MinHeapify(0);
    return root;
}

void MinHeap::insertKey(int k)
{
    size++;
    int i = size - 1;
    H[i] = k;

    // Bottom Up
    while (i != 0 && H[parent(i)] > H[i])
    {
        swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

int MinHeap::decreaseKey(int i, int k)
{
    int value = H[i];
    H[i] = k;
    // Bottom Up
    while (i != 0 && H[parent(i)] > H[i])
    {
        swap(H[parent(i)], H[i]);
        i = parent(i);
    }
    return value;
}

int MinHeap::deleteKey(int i)
{
    int value = H[i];
    decreaseKey(i, INT_MIN);
    extractMin();
    return value;
}

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main()
{
    int A[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17, 2};
    int n = 12;

    MinHeap h(A, n);

    printArray(A, n);

    cout << h.extractMin() << endl;

    h.insertKey(12);
    printArray(A, n);

    h.decreaseKey(7, 1);
    printArray(A, n);

    h.deleteKey(2);
    printArray(A, n);

    return 0;
}