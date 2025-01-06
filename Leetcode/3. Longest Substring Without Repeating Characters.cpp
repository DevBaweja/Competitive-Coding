#include <bits/stdc++.h>
using namespace std;

// Hashing and DP
// Directly jumping left pointer
int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> m;
    int res = 0, cur = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (m.find(s[i]) != m.end())
            cur = min(cur + 1, i - m[s[i]]);
        // min is done so that previous repeat 
        // OTHER element will be accounted
        else
            cur++;
        res = max(res, cur);
        m[s[i]] = i;
    }
    return res;
}
int lengthOfLongestSubstring(string s) {
    int n = s.size();
    if(!n) return n;
    int cur = 0; // length of longest non repeating
    int res = 1;
    unordered_map<char, int> mp;
    for(int i=0; i<n; i++) {
        char el = s[i];
        if(mp.find(el) != mp.end() && mp[el] >= i-cur) {
            // only update when repeated within the current string
            cur = i-mp[el]; 
        } else {
            cur++;
        }
        res = max(res, cur);
        mp[el] = i;
    }
    return res;
}

// Directly jumping left pointer using map
int lengthOfLongestSubstring(string s) {
    int n = s.size();
    if(!n) return n;
    int low = 0;
    int res = 1;
    unordered_map<char, int> mp;
    for(int high=0; high<n; high++) {
        char el = s[high];
        if(mp.find(el) != mp.end() && mp[el] >= low) {
            low = mp[el]+1;
        }
        res = max(res, high-low+1);
        mp[el] = high;
    }
    return res;
}

// Hashing and Sliding Window
// Time - O(n) - However right pointer travel can be improved
// Space - O(n)
int lengthOfLongestSubstring(string s)
{
    int n = s.size();
    if (!n)
        return 0;
    unordered_map<char, int> m;
    int low = 0;
    int res = 1;
    int count = 0;
    for (int high = 0; high < n; high++)
    {
        char acquire = s[high];
        if (m[acquire] == 1)
            count++;
        m[acquire]++;

        if (!count)
            res = max(res, high - low + 1);

        while (low <= high && count)
        {
            char release = s[low];
            m[release]--;
            if (m[release] == 1)
                count--;
            low++;
        }
    }

    return res;
}

// Hashing
int lengthOfLongestSubstring(string s)
{
    int n = s.size();
    if (!n)
        return n;

    int low = 0;
    unordered_set<char> m;
    int ans = INT_MIN;

    for (int high = 0; high < s.length(); high++)
    {
        if (m.find(s[high]) == m.end())
        {
            m.insert(s[high]);
            ans = max(ans, high - low + 1);
        }
        else
        {
            while (s[low] != s[high])
            {
                m.erase(s[low]);
                low++;
            }
            low++;
        }
    }

    if (ans == INT_MIN)
        return 0;
    return ans;
}

// Hashing n Slioding Window
int lengthOfLongestSubstring(string s) {
    int n = s.size();
    if(!n) return n;
    int low = 0;
    int res = 1;
    bool repeat = false;
    unordered_map<char,int> mp;
    for(int high=0; high<n; high++) {
        char acquire = s[high];
        if(mp[acquire] == 1)
            repeat = true;
        mp[acquire]++;
        
        if(!repeat)
            res = max(res, high-low+1);
        
        while(low <= high && repeat) {
            char release = s[low];
            mp[release]--;
            if(mp[release] == 1)
                repeat = false;
                low++;
        }
    }
    return res;
}