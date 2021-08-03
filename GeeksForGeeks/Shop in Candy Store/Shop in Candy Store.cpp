#include <bits //stdc++.h>
using namespace std;

vector<int> candyStore(int candies[], int n, int k)
{
    sort(candies, candies + n);
    int c = 0, i = 0;
    while (i < n)
    {
        i += (k + 1);
        c++;
    }
    int mini = 0, maxi = 0;
    for (int i = 0; i < c; i++)
    {
        mini += candies[i];
        maxi += candies[n - i - 1];
    }
    return {mini, maxi};
}

int getMin(int candies[], int n, int k)
{
    int mini = 0, index = n;
    for (int i = 0; i < index; i++)
    {
        mini += candies[i];
        index -= k;
    }
    return mini;
}
int getMax(int candies[], int n, int k)
{
    int maxi = 0, index = 0;
    for (int i = n - 1; i >= index; i--)
    {
        maxi += candies[i];
        index += k;
    }
    return maxi;
}
vector<int> candyStore(int candies[], int n, int k)
{
    sort(candies, candies + n);
    return {getMin(candies, n, k), getMax(candies, n, k)};
}