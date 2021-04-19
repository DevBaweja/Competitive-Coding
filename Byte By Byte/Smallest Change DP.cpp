#include <bits/stdc++.h>
using namespace std;

int change(int x, int n, vector<int> coins, vector<int> table)
{
    if (x == 0)
        return 0;

    int min_coins = x;
    for (int i = 0; i < n; i++)
    {
        if (x - coins[i] >= 0)
        {
            int sub_coins;
            if (table[x - coins[i]] == -1)
            {
                sub_coins = change(x - coins[i], n, coins, table);
                table[x - coins[i]] = sub_coins;
            }
            else
                sub_coins = table[x - coins[i]];
            min_coins = min(min_coins, sub_coins + 1);
        }
    }
    return min_coins;
}

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    vector<int> table(n + 1, -1);
    table[0] = 0;
    cout << change(x, n, coins, table);
    return 0;
}