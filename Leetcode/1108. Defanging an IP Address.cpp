#include <bits/stdc++.h>
using namespace std;

string replaceAll(string str, string from, string to)
{
    int start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}

string defangIPaddr(string address)
{
    address = replaceAll(address, ".", "[.]");
    return address;
}