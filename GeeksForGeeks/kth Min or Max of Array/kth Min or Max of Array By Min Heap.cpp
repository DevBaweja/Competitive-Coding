#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

class MinHeap
{
    int *H;
    int size;

public:
    MinHeap(int A[], int n); // Constructor
    int getMin() { return H[0]; }
    void MinHeapify(int i); // Heapify at node index i
    int extractMin();
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * (i + 1); }
};

MinHeap::MinHeap(int A[], int n)
{
    H = A;
    size = n;
    int i = size / 2 - 1; // All node except leafs
    while (i >= 0)
    {
        MinHeapify(i);
        i--;
    }
}

void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (r < size && H[r] < H[i])
        smallest = r;
    if (l < size && H[l] < H[i])
        smallest = l;
    // Swapping
    if (smallest != i)
    {
        swap(&H[i], &H[smallest]);
        MinHeapify(smallest);
    }
}

int MinHeap::extractMin()
{
    int root = H[0];
    H[0] = H[size - 1];
    MinHeapify(0);
    size--;
    return root;
}

// Heapify 1 node takes O(log(n)) - Height of tree
// Heapify all nodes takes O(n*log(n))
// However, leaf nodes don't need heapify.
// Last non leaf nodes = Parent of last node ie (n-1)
// ((n-1) - 1) / 2 = n/2 - 1
// In reverse order

// Time O(n+k*log(n))

int kthSmallest(int A[], int n, int k)
{
    MinHeap mh(A, n);

    for (int i = 0; i < k - 1; i++)
        mh.extractMin();

    return mh.getMin();
}

int main()
{
    int A[] = {12, 3, 5, 7, 19};
    int n = 5, k = 2;
    cout << kthSmallest(A, n, k);
    return 0;
}
//      12
//    3     5
//  7   19
