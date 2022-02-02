#include <bits/stdc++.h>
using namespace std;

vector<string> printVertically(string s)
{
    int n = s.size();
    vector<string> v;
    string temp = "";
    int maxi = 0;
    for (char el : s)
    {
        if (el == ' ')
        {
            v.push_back(temp);
            maxi = max(maxi, (int)temp.size());
            temp = "";
        }
        else
            temp += el;
    }
    v.push_back(temp);
    maxi = max(maxi, (int)temp.size());
    int k = v.size();

    vector<vector<char>> mat(k, vector<char>(maxi, ' '));
    vector<string> res;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < v[i].size(); j++)
            mat[i][j] = v[i][j];

    for (int i = 0; i < maxi; i++)
    {
        string temp = "";
        for (int j = 0; j < k; j++)
            temp += mat[j][i];
        res.push_back(temp);
    }

    for (string &el : res)
    {
        int m = el.size();
        int index = m - 1;
        while (index >= 0 && el[index] == ' ')
        {
            el.pop_back();
            index--;
        }
    }
    return res;
}