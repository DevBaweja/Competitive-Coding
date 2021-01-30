#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<int> Union(vector<int> A, vector<int> B, int n, int m)
{
    set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(A[i]);

    for (int i = 0; i < m; i++)
        s.insert(B[i]);

    return s;
}

set<int> Intersection(vector<int> A, vector<int> B, int n, int m)
{
    set<int> sA, sB;
    for (int i = 0; i < n; i++)
        sA.insert(A[i]);

    for (int i = 0; i < m; i++)
    {
        if (sA.find(B[i]) != sA.end())
            sB.insert(B[i]);
    }

    return sB;
}
// Time- O(n+m) under assumption that insert and search in set takes O(1)

int main()
{
    vector<int> A{7, 1, 5, 2, 3, 6};
    vector<int> B{3, 8, 6, 20, 7};
    int n = A.size();
    int m = B.size();

    set<int> un = Union(A, B, n, m);
    for (set<int>::iterator it = un.begin(); it != un.end(); it++)
        cout << *it << " ";
    cout << endl;

    set<int> in = Intersection(A, B, n, m);
    for (set<int>::iterator it = in.begin(); it != in.end(); it++)
        cout << *it << " ";

    return 0;
}