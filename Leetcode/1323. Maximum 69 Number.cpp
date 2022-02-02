#include <bits/stdc++.h>
using namespace std;
// Brute Force
int maximum69Number(int num)
{
    vector<int> number;
    int temp = num;
    while (num)
    {
        number.push_back(num % 10);
        num /= 10;
    }
    int n = number.size();
    bool flag = false;
    for (int i = n - 1; i >= 0; i--)
    {
        if (number[i] == 6)
        {
            number[i] = 9;
            flag = true;
            break;
        }
    }
    if (!flag)
        return temp;
    int res = 0;
    for (int i = n - 1; i >= 0; i--)
        res = res * 10 + number[i];
    return res;
}
