/*
Given a string S of '(' and ')' parentheses, we add the minimum number of parentheses ( '(' or ')', and in any positions ) so that the resulting parentheses string is valid.

Formally, a parentheses string is valid if and only if:

It is the empty string, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
Given a parentheses string, return the minimum number of parentheses we must add to make the resulting string valid.

 

Example 1:

Input: "())"
Output: 1
Example 2:

Input: "((("
Output: 3
Example 3:

Input: "()"
Output: 0
Example 4:

Input: "()))(("
Output: 4
 

Note:

S.length <= 1000
S only consists of '(' and ')' characters.
*/
// With Stack
// #include <string>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int count = 0;
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                st.push(s[i]);
            else if (s[i] == ')' && !st.empty())
                st.pop();
            else
                count++;
        }
        if (!st.empty())
            count += st.size();
        return count;
    }
};

// Without Stack
class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int count = 0;
        int st = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                st++;
            else if (s[i] == ')' && st != 0)
                st--;
            else
                count++;
        }
        if (st != 0)
            count += st;
        return count;
    }
};