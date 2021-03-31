#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 8;
    string board[n];
    for (int i = 0; i < n; i++)
        cin >> board[i];

    int perm[n];
    int result = 0;
    iota(perm, perm + n, 0);

    bool diagonal[2 * n - 1];
    do
    {
        bool valid = 1;
        // Empty
        for (int i = 0; i < n; i++)
            valid &= board[i][perm[i]] == '.';
        // Diagonals
        memset(diagonal, 0, 2 * n - 1);
        for (int i = 0; i < n; i++)
        {
            int index = i + perm[i];
            if (diagonal[index])
                valid = 0;
            diagonal[index] = 1;
        }
        memset(diagonal, 0, 2 * n - 1);
        for (int i = 0; i < n; i++)
        {
            int index = i + n - 1 - perm[i];
            if (diagonal[index])
                valid = 0;
            diagonal[index] = 1;
        }
        result += valid;
    } while (next_permutation(perm, perm + n));
    cout << result << endl;
    return 0;
}