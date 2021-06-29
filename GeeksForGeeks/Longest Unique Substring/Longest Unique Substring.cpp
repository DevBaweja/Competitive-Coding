#include <bits/stdc++.h>
using namespace std;

/*
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int res = 0, cur = 0;
        for(int i=0;i<s.size();i++){
            if(m.find(s[i]) != m.end())
                cur = min(cur+1,i-m[s[i]]);
            else
                cur++;
            res = max(res, cur);
            m[s[i]] = i;
        }
        return res;
    }
*/

int longestUniqueSubsttr(string s)
{
    // unordered_map<char,int> m;
    vector<int> v(26, -1);
    int res = 0, cur = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (v[s[i] - 'a'] != -1)
            cur = min(cur + 1, i - v[s[i] - 'a']);
        else
            cur++;
        res = max(res, cur);
        v[s[i] - 'a'] = i;
    }
    return res;
}