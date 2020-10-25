#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> V;
    // Array
    cout << V.size() << endl;
    V.push_back(1);
    V.push_back(2);
    V.push_back(3);
    // [ 1, 2, 3 ]

    // Access Vector
    cout << V[2] << endl;    // No range check
    cout << V.at(2) << endl; // throw range_error exception of out of range

    // Traverse
    for (int i = 0; i < V.size(); i++)
        cout << V[i] << " ";

    // Iterator Traverse
    for (vector<int>::iterator itr = V.begin(); itr != V.end(); itr++)
        cout << *itr << " ";

    /*
    for (int v : V)
        cout << v << " ";
    */

    //    Vector is dynamically allocated contiguous array in memory
    int *A = &V[0];
}

/*
Vector
[][][][][
Fast insert and remove at the end 
O(1)
Slow insert and remove at the start or middle
O(n)
Slow Search
O(n)
*/
