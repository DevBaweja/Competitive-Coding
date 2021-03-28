#include <iostream>
using namespace std;

int main()
{
    int r, o, c;
    cin >> r >> o >> c;
    if (c + 36 * (20 - o) > r)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}