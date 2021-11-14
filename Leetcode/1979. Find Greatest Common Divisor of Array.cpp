#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (a == b)
        return a;
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}

int gcd(int a, int b)
{
    if (!a)
        return b;
    if (!b)
        return a;
    if (a > b)
        return gcd(a % b, b);
    return gcd(a, b % a);
}

int findGCD(vector<int> &nums)
{
    int mini = *min_element(nums.begin(), nums.end());
    int maxi = *max_element(nums.begin(), nums.end());
    return gcd(mini, maxi);
}