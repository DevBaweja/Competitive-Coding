#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Brute Force
int isVowel(char ch)
{
    vector<int> v{'a', 'e', 'i', 'o', 'u'};
    for (int el : v)
        if (el == ch)
            return 1;
    return 0;
}
ll countVowels(string word)
{
    int n = word.size();
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
                ans += isVowel(word[k]);
        }
    }
    return ans;
}

// Brute Force
ll countVowels(string word)
{
    int n = word.size();
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int cur = 0;
        for (int j = i; j < n; j++)
        {
            cur += isVowel(word[j]);
            ans += cur;
        }
    }
    return ans;
}

// Optimiized
ll countVowels(string word)
{
    ll n = word.size();
    ll ans = 0;
    for (ll i = 0; i < n; i++)
        if (isVowel(word[i]))
            ans += (i + 1) * (n - i);
    ;
    return ans;
}