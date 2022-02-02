#include <bits/stdc++.h>
using namespace std;

// Sorting Insertion Sort and Brute Force Count Group
int findLatestStep(vector<int> &arr, int target)
{
    vector<int> temp;
    int n = arr.size();
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        int m = temp.size();
        int el = arr[i];
        int k = 0;
        while (k < m && el > temp[k])
            k++;
        temp.insert(temp.begin() + k, el);
        int j = 0;
        while (j <= m)
        {
            int cur = 1;
            while (j < m && temp[j] == temp[j + 1] - 1)
            {
                j++;
                cur++;
            }
            if (cur == target)
            {
                ans = i + 1;
                break;
            }
            j++;
        }
    }
    return ans;
}

// Binary Search Insert and Brute Force Count Group
int binarySearch(vector<int> &temp, int target)
{
    int n = temp.size();
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (target > temp[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
int findLatestStep(vector<int> &arr, int target)
{
    vector<int> temp;
    int n = arr.size();
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        int m = temp.size();
        int el = arr[i];

        temp.insert(temp.begin() + binarySearch(temp, el), el);
        int j = 0;
        while (j <= m)
        {
            int cur = 1;
            while (j < m && temp[j] == temp[j + 1] - 1)
            {
                j++;
                cur++;
            }
            if (cur == target)
            {
                ans = i + 1;
                break;
            }
            j++;
        }
    }
    return ans;
}

// Hashing and Update Size and Maintain Count
int findLatestStep(vector<int> &arr, int target)
{
    int n = arr.size();
    unordered_map<int, int> m;
    int res = -1;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int el = arr[i];
        if (m.find(el + 1) == m.end() && m.find(el - 1) == m.end())
        {
            m[el] = 1;
            if (m[el] == target)
            {
                res = i + 1;
                count++;
            }
            continue;
        }

        if (m.find(el + 1) != m.end() && m.find(el - 1) != m.end())
        {
            int prev = el - 1, next = el + 1;
            if (m[prev] == target)
                count--;
            if (m[next] == target)
                count--;
            int size = m[prev] + m[next] + 1;
            if (size == target)
                count++;
            m[el] = size;

            while (m.find(next) != m.end())
            {
                m[next] = size;
                next++;
            }
            while (m.find(prev) != m.end())
            {
                m[prev] = size;
                prev--;
            }

            if (count)
                res = i + 1;
            continue;
        }

        if (m.find(el + 1) != m.end())
        {
            int cur = el + 1;
            if (m[cur] == target)
                count--;
            int size = m[cur] + 1;
            if (size == target)
                count++;
            m[el] = size;
            while (m.find(cur) != m.end())
            {
                m[cur] = size;
                cur++;
            }
        }
        if (m.find(el - 1) != m.end())
        {
            int cur = el - 1;
            if (m[cur] == target)
                count--;
            int size = m[cur] + 1;
            if (size == target)
                count++;
            m[el] = size;
            while (m.find(cur) != m.end())
            {
                m[cur] = size;
                cur--;
            }
        }

        if (count)
            res = i + 1;
    }
    return res;
}

int findLatestStep(vector<int> &arr, int target)
{
    int ans = -1;
    int n = arr.size();
    unordered_map<int, int> mp;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int el = arr[i];
        if (mp.find(el - 1) == mp.end() && mp.find(el + 1) == mp.end())
        {
            mp[el] = 1;
            if (target == 1)
                count++;
            if (count)
                ans = i + 1;
            continue;
        }
        if (mp.find(el - 1) != mp.end() && mp.find(el + 1) != mp.end())
        {
            int prev = el - 1, next = el + 1;
            if (mp[prev] == target)
                count--;
            if (mp[next] == target)
                count--;

            mp[el] = mp[prev] + mp[next] + 1;
            while (mp.find(prev) != mp.end())
            {
                mp[prev] = mp[el];
                prev--;
            }
            while (mp.find(next) != mp.end())
            {
                mp[next] = mp[el];
                next++;
            }
            if (mp[el] == target)
                count++;
            if (count)
                ans = i + 1;
            continue;
        }

        if (mp.find(el - 1) != mp.end())
        {
            int prev = el - 1;
            if (mp[prev] == target)
                count--;

            mp[el] = mp[prev] + 1;
            while (mp.find(prev) != mp.end())
            {
                mp[prev] = mp[el];
                prev--;
            }
        }
        if (mp.find(el + 1) != mp.end())
        {
            int next = el + 1;
            if (mp[next] == target)
                count--;

            mp[el] = mp[next] + 1;
            while (mp.find(next) != mp.end())
            {
                mp[next] = mp[el];
                next++;
            }
        }

        if (mp[el] == target)
            count++;
        if (count)
            ans = i + 1;
    }
    return ans;
}

// Handles Edges No Loop
int findLatestStep(vector<int> &arr, int target)
{
    int ans = -1;
    int n = arr.size();
    unordered_map<int, int> mp;

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int el = arr[i];
        if (mp.find(el - 1) == mp.end() && mp.find(el + 1) == mp.end())
        {
            mp[el] = 1;
            if (target == 1)
                count++;
            if (count)
                ans = i + 1;
            continue;
        }
        if (mp.find(el - 1) != mp.end() && mp.find(el + 1) != mp.end())
        {
            int prev = el - 1, next = el + 1;
            if (mp[prev] == target)
                count--;
            if (mp[next] == target)
                count--;

            mp[el] = mp[prev] + mp[next] + 1;

            mp[el - mp[prev]] = mp[el];
            mp[el + mp[next]] = mp[el];

            if (mp[el] == target)
                count++;
            if (count)
                ans = i + 1;
            continue;
        }

        if (mp.find(el - 1) != mp.end())
        {
            int prev = el - 1;
            if (mp[prev] == target)
                count--;

            mp[el] = mp[prev] + 1;
            mp[el - mp[prev]] = mp[el];
        }
        if (mp.find(el + 1) != mp.end())
        {
            int next = el + 1;
            if (mp[next] == target)
                count--;

            mp[el] = mp[next] + 1;
            mp[el + mp[next]] = mp[el];
        }

        if (mp[el] == target)
            count++;
        if (count)
            ans = i + 1;
    }
    return ans;
}

// Space Optimized
int findLatestStep(vector<int> &arr, int target)
{
    int n = arr.size();
    int res = -1;
    vector<int> length(n + 2);
    vector<int> count(n + 1);
    for (int i = 0; i < n; i++)
    {
        int el = arr[i];
        int left = length[el - 1], right = length[el + 1];
        length[el] = left + right + 1;
        length[el - left] = length[el + right] = length[el];
        count[left]--;
        count[right]--;
        count[length[el]]++;
        if (count[target])
            res = i + 1;
    }
    return res;
}

// Queue and Splitting Method Reverse
int findLatestStep(vector<int> &arr, int target)
{
    int n = arr.size();
    queue<pair<int, int>> q;
    q.push({1, n});
    int res = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        int el = arr[i];
        int t = q.size();
        while (t--)
        {
            pair<int, int> p = q.front();
            q.pop();
            int size = p.second - p.first + 1;
            if (size == target)
            {
                res = i + 1;
                break;
            }

            if (size < target)
                continue;

            if (p.first <= el && p.second >= el)
            {
                if (p.first <= el - 1)
                    q.push({p.first, el - 1});
                if (el + 1 <= p.second)
                    q.push({el + 1, p.second});
            }
            else
                q.push(p);
        }

        if (res != -1)
            break;
    }
    return res;
}
// TODO
// Union Find