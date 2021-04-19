#include <bits/stdc++.h>
using namespace std;

int change(int x, int n, vector<int> coins)
{
    if (x == 0)
        return 0;

    int min_coins = x;
    for (int i = 0; i < n; i++)
    {
        if (x - coins[i] >= 0)
        {
            int sub_coins = change(x - coins[i], n, coins);
            min_coins = min(min_coins, sub_coins + 1);
        }
    }
    return min_coins;
}
// Time - O(exp)

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    cout << change(x, n, coins);
    return 0;
}