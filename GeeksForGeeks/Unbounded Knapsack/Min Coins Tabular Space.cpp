#include <bits/stdc++.h>
using namespace std;

int minCoins(int coins[], int M, int V)
{
    vector<int> table(V + 1, INT_MAX);
    table[0] = 0;
    for (int i = 1; i <= V; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i >= coins[j])
            {
                int sub = table[i - coins[j]];
                if (sub != INT_MAX)
                    table[i] = min(table[i], 1 + sub);
            }
        }
    }
    if (table[V] == INT_MAX)
        return -1;
    return table[V];
}

int main()
{
    int V = 30;
    int M = 3;
    int coins[] = {25, 10, 5};
    cout << minCoins(coins, M, V);
    return 0;
}