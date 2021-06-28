#include <bits/stdc++.h>
using namespace std;

int cutRod(int price[], int n)
{
    int value[n + 1];
    value[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int maxValue = INT_MIN;
        for (int j = 0; j < i; j++)
            maxValue = max(maxValue, price[j] + value[i - j - 1]);
        value[i] = maxValue;
    }

    return value[n];
}

int main()
{
    int n = 8;
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << cutRod(price, n);
    return 0;
}