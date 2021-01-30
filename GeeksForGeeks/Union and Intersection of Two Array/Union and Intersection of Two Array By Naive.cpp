#include <iostream>
#include <vector>
using namespace std;

vector<int> Union(vector<int> A, vector<int> B, int n, int m)
{
    vector<int> v;
    for (int i = 0; i < n; i++)
        v.push_back(A[i]);

    for (int i = 0; i < m; i++)
    {
        bool found = false;
        for (int j = 0; j < n; j++)
        {
            if (B[i] == A[j])
            {
                found = true;
                break;
            }
        }
        if (!found)
            v.push_back(B[i]);
    }
    return v;
}

vector<int> Intersection(vector<int> A, vector<int> B, int n, int m)
{
    vector<int> v;

    for (int i = 0; i < m; i++)
    {
        bool found = false;
        for (int j = 0; j < n; j++)
        {
            if (B[i] == A[j])
            {
                found = true;
                break;
            }
        }
        if (found)
            v.push_back(B[i]);
    }
    return v;
}
// Time- O(nm)
// Searching is needed for every element

int main()
{
    vector<int> A{7, 1, 5, 2, 3, 6};
    vector<int> B{3, 8, 6, 20, 7};
    int n = A.size();
    int m = B.size();

    vector<int> un = Union(A, B, n, m);
    for (vector<int>::iterator it = un.begin(); it != un.end(); it++)
        cout << *it << " ";
    cout << endl;

    for (int i = 0; i < un.size(); i++)
        cout << un[i] << " ";
    // un.at(i)
    cout << endl;

    vector<int> in = Intersection(A, B, n, m);
    for (vector<int>::iterator it = in.begin(); it != in.end(); it++)
        cout << *it << " ";
    cout << endl;

    for (int i = 0; i < in.size(); i++)
        cout << in[i] << " ";
    // in.at(i)

    return 0;
}