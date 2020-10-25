#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<char, int> M;
    M.insert(pair<char, int>('a', 1));
    M.insert(make_pair('b', 2));
    // Key-Value Pair

    map<char, int>::iterator itr = M.begin();
    M.insert(itr, pair<char, int>('c', 3));

    map<char, int>::iterator it = M.find('a');
    // O(log(n))

    // Tranverse Map
    for (map<char, int>::iterator i = M.begin(); i != M.end(); i++)
        cout << (*i).first << "=>" << (*i).second << endl;

    multimap<char, int> MM;
    MM.insert(make_pair('a', 1));

    // Key cann't be modified
    multimap<char, int>::iterator i = MM.begin();
    // (*i).first = 'b';
}