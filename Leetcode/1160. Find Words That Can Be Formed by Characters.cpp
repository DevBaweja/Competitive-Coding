#include <bits/stdc++.h>
using namespace std;

void getFreq(string word, unordered_map<char, int> &m)
{
    for (int i = 0; i < word.length(); i++)
        m[word[i]]++;
}
int compareFreq(unordered_map<char, int> &mapA, unordered_map<char, int> &mapB)
{
    int isValid = 1;
    for (auto itr : mapB)
    {
        if (mapA[itr.first] < itr.second)
        {
            isValid = 0;
            break;
        }
    }
    return isValid;
}
int countCharacters(vector<string> &words, string chars)
{
    int count = 0;
    unordered_map<char, int> allChars;

    getFreq(chars, allChars);

    for (int i = 0; i < words.size(); i++)
    {
        unordered_map<char, int> allWords;
        getFreq(words[i], allWords);
        count += compareFreq(allChars, allWords) * words[i].length();
    }
    return count;
}