#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin >> x;
    for (int i = 1; i <= x; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
            cout << "FizzBuzz";
        else if (i % 3 == 0)
            cout << "Fizz";
        else if (i % 5 == 0)
            cout << "Buzz";
        else
            cout << i;
        cout << "\n";
    }
    return 0;
}