#include <iostream>
using namespace std;

// Backtracking
void permutate(string str, int l, int r)
{
    if (l == r)
        cout << str << " ";
    else
    {

        for (int i = l; i <= r; i++)
        {
            swap(str[l], str[i]);
            permutate(str, l + 1, r);
            // Backtrack
            swap(str[l], str[i]);
        }
    }
}
// Time - O(n*n!)
// n! permutations and O(n) to print a permutation.

int main()
{
    string str = "ABCD";
    int n = str.size();
    permutate(str, 0, n - 1);
    return 0;
}