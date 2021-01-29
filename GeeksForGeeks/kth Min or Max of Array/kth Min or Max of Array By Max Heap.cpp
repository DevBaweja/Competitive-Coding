#include <iostream>
using namespace std;

class MaxHeap
{
    int *H;
    int size;

public:
    MaxHeap(int A[], int n); // Constructor
    int getMax() { return H[0]; }
    void MaxHeapify(int i); // Heapify at node index i
    int extractMax();
    void replaceMax(int x)
    {
        H[0] = x;
        MaxHeapify(0);
    }
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * (i + 1); }
};

MaxHeap::MaxHeap(int A[], int n)
{
    H = A;
    size = n;
    int i = size / 2 - 1; // All node except leafs
    while (i >= 0)
    {
        MaxHeapify(i);
        i--;
    }
}

void MaxHeap::MaxHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l < size && H[l] > H[i])
        largest = l;
    if (r < size && H[r] > H[largest])
        largest = r;
    // Swapping
    if (largest != i)
    {
        swap(H[i], H[largest]);
        MaxHeapify(largest);
    }
}

int MaxHeap::extractMax()
{
    int root = H[0];
    H[0] = H[size - 1];
    MaxHeapify(0);
    size--;
    return root;
}

// Heapify 1 node takes O(log(n)) - Height of tree
// Heapify all nodes takes O(n*log(n))
// However, leaf nodes don't need heapify.
// Last non leaf nodes = Parent of last node ie (n-1)
// ((n-1) - 1) / 2 = n/2 - 1
// In reverse order

// Time O( k+ (n-k)*log(k))
// k - Build Heap
// (n-k)*log(k) - Extract Max

int kthSmallest(int A[], int n, int k)
{
    MaxHeap mh(A, k);

    for (int i = k; i < n; i++)
    {
        if (A[i] < mh.getMax())
            mh.replaceMax(A[i]);
    }

    return mh.getMax();
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
