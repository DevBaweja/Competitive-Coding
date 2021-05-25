#include <bits/stdc++.h>
using namespace std;

void printRLE(string str)
{
    string res = "";
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        while (i < n - 1 && str[i] == str[i + 1])
        {
            count++;
            i++;
        }
        res += str[i];
        res += to_string(count);
    }
    cout << res;
}

int main()
{
    string str = "wwwwaaadexxxxxxywww";
    printRLE(str);
    return 0;
}