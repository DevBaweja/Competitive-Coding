#include <bits/stdc++.h>
using namespace std;

string toLowerCase(string str)
{
    for (char &c : str)
        if (c >= 'A' && c <= 'Z')
            c -= 'A' - 'a';
    return str;
}