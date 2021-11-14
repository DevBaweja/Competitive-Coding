#include <bits/stdc++.h>
using namespace std;

// Brute Force
vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries)
{
    int n = s.size();
    vector<int> res;
    for (vector<int> query : queries)
    {
        int left = query[0], right = query[1];
        while (left <= right && s[left] == '*')
            left++;
        while (left <= right && s[right] == '*')
            right--;
        int count = 0;
        for (int k = left; k <= right; k++)
            if (s[k] == '*')
                count++;
        res.push_back(count);
    }
    return res;
}

pair<int, int> searchMax(vector<int> &v, int k)
{
    int low = 0;
    int high = v.size() - 1;
    pair<int, int> res = {-1, -1};
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (v[mid] >= k)
        {
            res = {v[mid], mid};
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}

pair<int, int> searchMin(vector<int> &v, int k)
{
    int low = 0;
    int high = v.size() - 1;
    pair<int, int> res = {-1, -1};
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (v[mid] <= k)
        {
            res = {v[mid], mid};
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return res;
}

// Binary Search
vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries)
{

    int n = s.size();
    vector<int> points;
    for (int i = 0; i < n; i++)
        if (s[i] == '|')
            points.push_back(i);

    vector<int> res;
    for (vector<int> query : queries)
    {
        pair<int, int> left = searchMax(points, query[0]);
        pair<int, int> right = searchMin(points, query[1]);

        int leftValue = left.first, rightValue = right.first;
        int leftIndex = left.second, rightIndex = right.second;
        int count;
        if (leftIndex == -1 || rightIndex == -1 || (leftIndex >= rightIndex))
            count = 0;
        else
            count = (rightValue - leftValue) - (rightIndex - leftIndex);
        res.push_back(count);
    }
    return res;
}