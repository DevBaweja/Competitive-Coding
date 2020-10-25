#include <iostream>
#include <set>

using namespace std;

int main()
{
    // No Duplicate
    set<int> S;
    S.insert(2);
    S.insert(1);
    S.insert(3);
    // [1,2,3]

    set<int>::iterator itr;
    itr = S.find(2);
    // Sequence container don't have find() member function

    pair<set<int>::iterator, bool> P;
    P = S.insert(1);
    if (!P.second)
        itr = P.first;

    S.insert(itr, 4);
    // As itr is unused
    // O(log(n)) -> O(1)
    // [1,2,3,4]

    S.erase(itr);
    // [2,3,4]
    S.erase(4);
    // [2,3]

    // Duplicate
    multiset<int> MS;
    MS.insert(1);
    MS.insert(1);

    for (multiset<int>::iterator itr = MS.begin(); itr != MS.end(); itr++)
        cout << *itr << " ";

    multiset<int>::iterator it = MS.begin();
    // Ms.insert(it, 2)
    // Insert is always successful
    // Set / Mutli Set Value of element cannot be modified
    // *it = 2;
    cout << *it << endl;
}
/*
Set
Insert at any place 
O(log(n))
Fast Search at any place
O(log(n))

Multi Set
Insert at any place 
O(log(n))
Fast Search at any place
O(long(n))
Traversing is slow(compared to vector and deque)
No random access, no [] operator
*/