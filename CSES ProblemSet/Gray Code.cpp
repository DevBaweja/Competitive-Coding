#include <bits/stdc++.h>
using namespace std;

vector<string> grayCode(int n)
{
    if (n == 1)
    {
        vector<string> b{"0", "1"};
        return b;
    }

    vector<string> res = grayCode(n - 1);

    vector<string> mres;
    for (int i = 0; i < res.size(); i++)
        mres.push_back("0" + res[i]);
    for (int i = res.size() - 1; i >= 0; i--)
        mres.push_back("1" + res[i]);
    return mres;
}

int main()
{
    int n;
    cin >> n;
    vector<string> res = grayCode(n);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << "\n";
}