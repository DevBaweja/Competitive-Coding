#include <bits/stdc++.h>
using namespace std;

// Bit Manipulation
vector<int> generateMasks(vector<string> &array, int n)
{
    vector<int> arrayMask(n);
    for (int i = 0; i < n; i++)
    {
        string temp = array[i];
        int mask = 0;
        for (char ch : temp)
            mask = mask | (1 << (ch - 'a'));
        arrayMask[i] = mask;
    }
    return arrayMask;
}

int main()
{
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
        cin >> words[i];
    int m;
    cin >> m;
    vector<string> puzzles(m);
    for (int i = 0; i < m; i++)
        cin >> puzzles[i];

    vector<int> wordMasks = generateMasks(words, n);
    vector<int> puzzleMasks = generateMasks(puzzles, m);

    for (int i = 0; i < m; i++)
    {
        string puzzle = puzzles[i];
        int puzzleMask = puzzleMasks[i];
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            string word = words[j];
            int wordMask = wordMasks[j];
            char first = puzzle[0];
            if ((wordMask & (1 << (first - 'a'))) &&
                ((wordMask & puzzleMask) == wordMask))
                count++;
        }
        cout << puzzle << " -> " << count << "\n";
    }
    return 0;
}

// Optimization
#include <bits/stdc++.h>
using namespace std;

int generateMask(string s)
{
    int mask = 0;
    for (char ch : s)
        mask = mask | (1 << (ch - 'a'));
    return mask;
}

int main()
{
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
        cin >> words[i];
    int m;
    cin >> m;
    vector<string> puzzles(m);
    for (int i = 0; i < m; i++)
        cin >> puzzles[i];

    unordered_map<char, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        string word = words[i];
        unordered_set<char> s;
        for (char ch : word)
        {
            if (s.find(ch) == s.end())
            {
                s.insert(ch);
                mp[ch].push_back(generateMask(word));
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        string puzzle = puzzles[i];
        int puzzleMask = generateMask(puzzle);
        char first = puzzle[0];
        vector<int> wordsMask = mp[first];
        int count = 0;
        for (int wordMask : wordsMask)
            if ((puzzleMask & wordMask) == wordMask)
                count++;
        cout << puzzle << " -> " << count << "\n";
    }
}