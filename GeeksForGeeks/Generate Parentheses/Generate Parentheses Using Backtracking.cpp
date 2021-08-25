#include <bits/stdc++.h>
using namespace std;

void AllParenthesisUtil(int n, int open, int close, string s, vector<string> &res)
{
    if (open == n && close == n)
    {
        res.push_back(s);
        return;
    }

    if (open > close)
        AllParenthesisUtil(n, open, close + 1, s + ")", res);
    if (open < n)
        AllParenthesisUtil(n, open + 1, close, s + "(", res);
}

vector<string> AllParenthesis(int n)
{
    vector<string> res;
    string s = "";
    AllParenthesisUtil(n, 0, 0, s, res);
    return res;
}