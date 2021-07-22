#include <bits/stdc++.h>
using namespace std;

// BFS
int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{

    unordered_set<string> words;
    for (int i = 0; i < wordList.size(); i++)
        words.insert(wordList[i]);

    if (words.find(endWord) == words.end())
        return 0;

    int wordSize = beginWord.size();
    queue<string> q;
    q.push(beginWord);
    int len = 0;
    while (!q.empty())
    {
        len++;
        int qsize = q.size();
        while (qsize--)
        {
            string s = q.front();
            q.pop();
            for (int k = 0; k < wordSize; k++)
            {
                char org = s[k];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    s[k] = c;
                    if (s == endWord)
                        return len + 1;
                    if (words.find(s) == words.end())
                        continue;

                    words.erase(s);
                    q.push(s);
                }
                s[k] = org;
            }
        }
    }
    return 0;
}