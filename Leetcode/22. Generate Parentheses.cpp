#include <bits/stdc++.h>
using namespace std;

void generateParenthesisUtil(int n, int open, int close, string str, vector<string> &res)
{
    if (close == n)
    {
        res.push_back(str);
        return;
    }

    if (open > close)
        generateParenthesisUtil(n, open, close + 1, str + ")", res);
    if (open < n)
        generateParenthesisUtil(n, open + 1, close, str + "(", res);
}
vector<string> generateParenthesis(int n)
{
    vector<string> res;
    int open = 0, close = 0;
    string str = "";
    generateParenthesisUtil(n, open, close, str, res);
    return res;
}