#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Union(vector<int> A, vector<int> B, int n, int m)
{
    vector<int> v;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (A[i] < B[j])
            v.push_back(A[i++]);
        else if (A[i] > B[j])
            v.push_back(B[j++]);
        else
        {
            v.push_back(A[i]);
            i++;
            j++;
        }
    }

    while (i < n)
        v.push_back(A[i++]);

    while (j < m)
        v.push_back(B[j++]);

    return v;
}

vector<int> Intersection(vector<int> A, vector<int> B, int n, int m)
{
    vector<int> v;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (A[i] < B[j])
            i++;
        else if (A[i] > B[j])
            j++;
        else
        {
            v.push_back(A[i]);
            i++;
            j++;
        }
    }

    return v;
}
// Time- O(n*log(n) + m*log(m))
// Sorting each array requires n*log(n) + m*log(m)
// Applying on two sorted array techniques in O(n+m)

int main()
{
    vector<int> A{7, 1, 5, 2, 3, 6};
    vector<int> B{3, 8, 6, 20, 7};
    int n = A.size();
    int m = B.size();

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<int> un = Union(A, B, n, m);
    for (int i = 0; i < un.size(); i++)
        cout << un[i] << " ";
    cout << endl;

    vector<int> in = Intersection(A, B, n, m);
    for (int i = 0; i < in.size(); i++)
        cout << in[i] << " ";

    return 0;
}