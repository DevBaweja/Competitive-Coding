#include <bits/stdc++.h>
using namespace std;

// Recursive
void recursion(vector<string> &nums, string str, string &ans)
{
    if (str.size() == nums.size())
    {
        if (find(nums.begin(), nums.end(), str) == nums.end())
            ans = str;
        return;
    }
    recursion(nums, str + "0", ans);
    recursion(nums, str + "1", ans);
}

string findDifferentBinaryString(vector<string> &nums)
{
    int n = nums.size();
    vector<string> v;
    string ans = "";
    string str = "";
    recursion(nums, str, ans);
    return ans;
}

// Diagonality
string findDifferentBinaryString(vector<string> &nums)
{
    int n = nums.size();
    string ans = "";
    for (int index = 0; index < n; index++)
        ans += nums[index][index] == '0' ? '1' : '0';
    return ans;
}