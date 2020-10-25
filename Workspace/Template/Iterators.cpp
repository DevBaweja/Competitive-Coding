#include <iostream>
#include <vector>
#include <algorithm>
// #include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<int> V;
    V.push_back(3);
    V.push_back(2);
    V.push_back(1);

    vector<int>::iterator itr1 = V.begin();
    vector<int>::iterator itr2 = V.end();

    for (vector<int>::iterator itr = itr1; itr != itr2; ++itr)
        cout << *itr << endl;

    sort(itr1, itr2);

    for (vector<int>::iterator itr = itr1; itr != itr2; ++itr)
        cout << *itr << endl;
}