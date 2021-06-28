#include <bits/stdc++.h>
using namespace std;

int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
{
    unordered_set<string> words;
    for (int i = 0; i < wordList.size(); i++)
        words.insert(wordList[i]);
    if (words.find(targetWord) == words.end())
        return 0;
    queue<string> q;
    q.push(startWord);
    int wordSize = startWord.size();
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
                int org = s[k];
                for (char x = 'a'; x <= 'z'; x++)
                {
                    s[k] = x;
                    if (s == targetWord)
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

int main()
{
    vector<string> wordList{"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";
    cout << wordLadderLength(startWord, targetWord, wordList);
    return 0;
}