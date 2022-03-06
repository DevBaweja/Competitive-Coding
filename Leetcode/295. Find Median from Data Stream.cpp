#include <bits/stdc++.h>
using namespace std;

// Two Sets
class MedianFinder
{
public:
    MedianFinder()
    {
    }

    set<pair<int, int>> s1, s2;
    int counter = 0;
    void addNum(int num)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        if (!n1)
        {
            s1.insert({num, counter++});
            return;
        }
        if (!n2)
        {
            if ((*(s1.begin())).first > num)
            {
                s2.insert(*s1.begin());
                s1.erase(s1.begin());
                s1.insert({num, counter++});
            }
            else
                s2.insert({num, counter++});
            return;
        }

        int cand = (*s2.begin()).first;
        if (num <= cand)
        {
            s1.insert({num, counter++});
            n1 += 1;
            if (n1 - n2 == 2)
            {
                s2.insert(*(--s1.end()));
                s1.erase(--s1.end());
            }
        }
        else
        {
            s2.insert({num, counter++});
            n2 += 1;
            if (n2 - n1 == 1)
            {
                s1.insert(*(s2.begin()));
                s2.erase(s2.begin());
            }
        }
    }

    double findMedian()
    {
        int n1 = s1.size(), n2 = s2.size();
        if ((n1 + n2) & 1)
        {
            return (*(--s1.end())).first;
        }
        return ((double)((*(--s1.end())).first) + (*(s2.begin())).first) / 2;
    }
};

// Two Priority Queue
class MedianFinder
{
public:
    MedianFinder()
    {
    }
    priority_queue<int, vector<int>> left;
    priority_queue<int, vector<int>, greater<int>> right;

    void addNum(int num)
    {
        int n1 = left.size();
        int n2 = right.size();

        if (!n1)
        {
            left.push(num);
            return;
        }
        if (!n2)
        {
            if (left.top() > num)
            {
                right.push(left.top());
                left.pop();
                left.push(num);
            }
            else
                right.push(num);
            return;
        }

        int cand = right.top();
        if (num <= cand)
        {
            left.push(num);
            n1 += 1;
            if (n1 - n2 == 2)
            {
                right.push(left.top());
                left.pop();
            }
        }
        else
        {
            right.push(num);
            n2 += 1;
            if (n2 - n1 == 1)
            {
                left.push(right.top());
                right.pop();
            }
        }
    }

    double findMedian()
    {
        int n1 = left.size(), n2 = right.size();
        if ((n1 + n2) & 1)
        {
            return left.top();
        }
        return ((double)left.top() + right.top()) / 2;
    }
};

// Two Priority Queue with left and right temp insertion
class MedianFinder
{
public:
    priority_queue<int, vector<int>> left;
    priority_queue<int, vector<int>, greater<int>> right;
    bool turn;
    MedianFinder()
    {
        turn = true;
    }

    void addNum(int num)
    {
        if (turn)
        {
            right.push(num);
            left.push(right.top());
            right.pop();
        }
        else
        {
            left.push(num);
            right.push(left.top());
            left.pop();
        }
        turn = !turn;
    }

    double findMedian()
    {
        int n1 = left.size(), n2 = right.size();
        if ((n1 + n2) & 1)
            return left.top();
        return ((double)left.top() + right.top()) / 2;
    }
};

// Frequency Count Median
class MedianFinder
{
public:
    int n;
    vector<int> freq;
    int count;
    MedianFinder()
    {
        int n = 101;
        this->n = n;
        vector<int> freq(n, 0);
        this->freq = freq;
        count = 0;
    }

    void addNum(int num)
    {
        freq[num]++;
        count++;
    }

    double findMedian()
    {
        int t = (count - 1) / 2 + 1;
        for (int i = 0; i < n; i++)
        {
            t -= freq[i];
            if (count & 1 && t <= 0)
                return i;
            if (!(count & 1))
            {
                if (t < 0)
                    return i;
                if (!t)
                {
                    int r = i;
                    i++;
                    while (i < n)
                    {
                        if (freq[i] > 0)
                            return (double)(r + i) / 2;
                        i++;
                    }
                }
            }
        }
        return 0;
    }
};

// Frequency Map
class MedianFinder
{
public:
    map<int, int> freq;
    int count;
    MedianFinder()
    {
        count = 0;
    }

    void addNum(int num)
    {
        freq[num]++;
        count++;
    }

    double findMedian()
    {
        int t = (count - 1) / 2 + 1;
        int r = INT_MAX;
        for (pair<int, int> p : freq)
        {
            t -= p.second;
            if (count & 1 && t <= 0)
                return p.first;
            if (!(count & 1))
            {
                if (t < 0)
                {
                    if (r == INT_MAX)
                        return p.first;
                    return ((double)p.first + r) / 2;
                }
                if (!t)
                    r = p.first;
            }
        }
        return 0;
    }
};

// Linked List Middle, HashMap