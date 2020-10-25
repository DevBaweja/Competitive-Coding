#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    list<int> L;
    // Double Linked List
    L.push_back(20);
    L.push_front(10);
    L.push_back(30);
    // [10,20,30]

    // No Random Access

    list<int>::iterator itr = find(L.begin(), L.end(), 10);
    // itr is at specific value
    // itr -> index 0

    L.insert(itr, 0);
    // [0,10,20,30]

    itr++;

    L.erase(itr);
    // [0,20,30]
    // Tranverse
    for (list<int>::iterator itr = L.begin(); itr != L.end(); ++itr)
        cout
            << *itr << " ";

    //
    // list<int> LN;
    // L.splice(itr, LN, itr_A, itr_B)
    // O(1)
    // List N is splice from A to B and added to List L at itr position
}
/*
List
]=[]=[]=[]=[]=[

Fast insert and remove at any place
O(1)
Slow Search
O(n)
No random access, no [] operator 
*/
/*
Forward List
]-[]-[]-[]-[]-[
*/
