#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.size() != s2.size())
        return false;
    string temp = s1 + s1;
    cout << (temp.find(s2) != string::npos);
}

int main()
{
}