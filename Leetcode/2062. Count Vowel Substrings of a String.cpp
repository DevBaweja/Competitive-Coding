#include <bits/stdc++.h>
using namespace std;

// Brute Force
bool isVowel(char ch)
{
    vector<char> v{'a', 'e', 'i', 'o', 'u'};
    for (char el : v)
        if (el == ch)
            return true;
    return false;
}

int countVowelSubstrings(string word)
{
    int size = 5;
    int n = word.size();
    int count = 0;
    for (int i = 0; i < n - size + 1; i++)
    {
        unordered_map<char, int> m;
        for (int j = i; j < n; j++)
        {
            if (!isVowel(word[j]))
                break;
            m[word[j]]++;
            if (m.size() == size)
                count++;
        }
    }
    return count;
}

// Sliding Window
bool isVowel(char ch)
{
    vector<char> v{'a', 'e', 'i', 'o', 'u'};
    for (char c : v)
        if (c == ch)
            return true;
    return false;
}

int countVowelSubstrings(string word)
{
    int n = word.size();
    int low = 0;
    int mid = 0;
    unordered_map<char, int> m;
    int ans = 0;
    int size = 5;
    for (int high = 0; high < n; high++)
    {
        if (isVowel(word[high]))
        {
            m[word[high]]++;

            while (m.size() == size)
            {
                m[word[mid]]--;
                if (!m[word[mid]])
                    m.erase(word[mid]);
                mid++;
            }
            ans += mid - low;
        }
        else
        {
            m.clear();
            low = mid = high + 1;
        }
    }

    return ans;
}
