#include <bits/stdc++.h>
using namespace std;

// Hashset
int getSquare(int n)
{
    int res = 0;
    while (n)
    {
        int r = n % 10;
        res += r * r;
        n /= 10;
    }
    return res;
}
bool isHappy(int n)
{
    unordered_set<int> s;
    while (n != 1 && s.find(n) == s.end())
    {
        s.insert(n);
        n = getSquare(n);
    }
    return n == 1;
}

// Floyd Cycle
int getSquare(int n)
{
    int res = 0;
    while (n)
    {
        int r = n % 10;
        res += r * r;
        n /= 10;
    }
    return res;
}
bool isHappy(int n)
{
    int slow = n, fast = getSquare(n);
    while (fast != 1 && slow != fast)
    {
        slow = getSquare(slow);
        fast = getSquare(getSquare(fast));
    }
    return fast == 1;
}