#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int leftMinPrice = INT_MAX;
    int leftMaxProfit = 0;
    vector<int> dpLeft(n, 0);
    for (int i = 0; i < n; i++)
    {
        leftMinPrice = min(leftMinPrice, A[i]);
        leftMaxProfit = max(leftMaxProfit, A[i] - leftMinPrice);
        dpLeft[i] = leftMaxProfit;
    }

    int rightMaxPrice = INT_MIN;
    int rightMaxProfit = 0;
    vector<int> dpRight(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        rightMaxPrice = max(rightMaxPrice, A[i]);
        rightMaxProfit = max(rightMaxProfit, rightMaxPrice - A[i]);
        dpRight[i] = rightMaxProfit;
    }

    int res = INT_MIN;
    for (int i = 0; i < n; i++)
        res = max(res, dpLeft[i] + dpRight[i]);
    cout << res;
}