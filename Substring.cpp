#include <bits/stdc++.h>
using namespace std;
const int maxn = 300011;
char s[maxn];
int deg[maxn], d[maxn];
vector<int> w[maxn];

int Find(int u, int c, string s)
{
    if (d[u] != -1)
        return d[u];
    d[u] = 0;
    for (int v : w[u])
    {
        d[u] = max(d[u], Find(v, c, s));
    }
    d[u] += (s[u - 1] == c + 'a');
    return d[u];
}

int beauty(int n, int m, string s, int x[], int y[])
{

    for (int i = 0; i < m; ++i)
    {

        w[x[i]].push_back(y[i]);
        ++deg[y[i]];
    }
    int ct = 0;
    queue<int> que;
    for (int i = 1; i <= n; ++i)
    {
        if (!deg[i])
            que.push(i), ++ct;
    }
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        for (int v : w[u])
        {
            if (--deg[v] == 0)
                que.push(v), ++ct;
        }
    }
    if (ct < n)
        return -1;
    int ans = 0;
    for (int c = 0; c < 26; ++c)
    {
        memset(d, 0xff, sizeof d);
        for (int i = 1; i <= n; ++i)
            ans = max(ans, Find(i, c, s));
    }
    return ans;
}

int main()
{
    int n = 5, m = 4;
    string s = "abaca";
    int x[] = {1, 1, 3, 4};
    int y[] = {2, 3, 4, 5};

    cout << beauty(n, m, s, x, y);
}