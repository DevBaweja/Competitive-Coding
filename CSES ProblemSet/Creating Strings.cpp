#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;

    sort(str.begin(), str.end());
    vector<string> result;

    do
        result.push_back(str);
    while (next_permutation(str.begin(), str.end()));

    cout << result.size() << "\n";
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << "\n";
    return 0;
}