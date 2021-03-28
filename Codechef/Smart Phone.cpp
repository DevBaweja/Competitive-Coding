#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    sort(A.begin(), A.end());

    ll result = 0;
    for (int i = 0; i < n; i++)
        result = max(result, (n - i) * 1ll * A[i]);
    cout << result << endl;
}