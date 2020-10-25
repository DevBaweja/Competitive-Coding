#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> D;
    // Array
    cout << D.size() << endl;
    D.push_back(2);
    D.push_front(1);
    D.push_back(3);
    // [ 1, 2, 3 ]

    // Access Deque
    cout << D[2] << endl;    // No range check
    cout << D.at(2) << endl; // throw range_error exception of out of range

    // Traverse
    for (int i = 0; i < D.size(); i++)
        cout << D[i] << " ";

    // Iterator Traverse
    for (deque<int>::iterator itr = D.begin(); itr != D.end(); itr++)
        cout << *itr << " ";

    cout << endl;
    /*
    for (int d : D)
        cout << d << " ";
    */
}

/*
Deque
][][][][][
Fast insert and remove at the end 
O(1)
Slow insert and remove at the start or middle
O(n)
Slow Search
O(n)
*/
