#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int> A, int l, int r, int el)
{
    if (r >= l)
    {
        int mid = (l + r) / 2;
        if (A[mid] == el)
            return mid;
        if (el < A[mid])
            return binarySearch(A, l, mid - 1, el);
        if (el > A[mid])
            return binarySearch(A, mid + 1, r, el);
    }
    return -1;
}

vector<int> Union(vector<int> A, vector<int> B, int n, int m)
{
    vector<int> v;
    for (int i = 0; i < n; i++)
        v.push_back(A[i]);

    for (int i = 0; i < m; i++)
        if (binarySearch(A, 0, n - 1, B[i]) == -1)
            v.push_back(B[i]);

    return v;
}

vector<int> Intersection(vector<int> A, vector<int> B, int n, int m)
{
    vector<int> v;

    for (int i = 0; i < m; i++)
        if (binarySearch(A, 0, n - 1, B[i]) != -1)
            v.push_back(B[i]);

    return v;
}
// Time- O(min( n*log(n) + m*log(n), m*log(m) + n*log(m) ) = O( (n+m)*log(n), (m+n)*log(m) )
// if n < m
// Sorting O( n*log(n) )
// Searching m times - O( m*log(n) )

int main()
{
    vector<int> A{7, 1, 5, 2, 3, 6};
    vector<int> B{3, 8, 6, 20, 7};
    int n = A.size();
    int m = B.size();

    if (n > m)
    {
        vector<int> temp = A;
        A = B;
        B = temp;
        swap(m, n);
    }

    sort(A.begin(), A.end());

    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;

    for (int i = 0; i < B.size(); i++)
        cout << B[i] << " ";
    cout << endl;

    vector<int> un = Union(A, B, n, m);

    for (int i = 0; i < un.size(); i++)
        cout << un[i] << " ";
    cout << endl;

    vector<int> in = Intersection(A, B, n, m);
    for (int i = 0; i < in.size(); i++)
        cout << in[i] << " ";

    return 0;
}