#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(string arr[], int n)
{
    string result = arr[0];
    for (int i = 1; i < n; i++)
    {
        string temp = arr[i];
        if (temp.length() < result.length())
            result = result.substr(0, temp.length());
        for (int j = 0; j < temp.length(); j++)
        {
            if (temp[j] != result[j])
            {
                if (j == 0)
                    return "-1";
                result = result.substr(0, j);
                break;
            }
        }
    }
    return result;
}