#include <bits/stdc++.h>
using namespace std;

map<char, int> generate(string s)
{
    map<char, int> temp;
    for (int i = 0; i < s.length(); i++)
        temp[s[i]]++;
    return temp;
}

map<char, int> intersection(map<char, int> A, map<char, int> B)
{
    map<char, int> temp;
    for (map<char, int>::iterator itr = A.begin(); itr != A.end(); ++itr)
    {
        if (B[itr->first] > 0)
            temp[itr->first] = min(itr->second, B[itr->first]);
    }
    return temp;
}

vector<string> commonChars(vector<string> &A)
{

    map<string, map<char, int>> big;
    for (int i = 0; i < A.size(); i++)
        big[A[i]] = generate(A[i]);

    map<char, int> result(big[A[0]]);
    for (map<string, map<char, int>>::iterator itr = big.begin(); itr != big.end(); ++itr)
    {
        map<char, int> intersect(itr->second);
        result = intersection(result, intersect);
    }

    vector<string> finalresult;
    for (map<char, int>::iterator itr = result.begin(); itr != result.end(); ++itr)
    {
        int count = itr->second;
        string s(1, itr->first);
        while (count--)
            finalresult.push_back(s);
    }
    return finalresult;
}