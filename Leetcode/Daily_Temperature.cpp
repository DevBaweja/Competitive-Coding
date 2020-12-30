/*
Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].
*/
// Brute Force
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        vector<int> v;

        for (int i = 0; i < T.size(); i++)
        {
            int c = 1;
            int j;

            for (j = i + 1; j < T.size(); j++)
            {

                if (T[j] > T[i])
                    break;
                c++;
            }
            if (j == T.size())
                c = 0;
            v.push_back(c);
        }
        return v;
    }
};

// With Stack
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        vector<int> v(T.size());
        stack<int> s;

        for (int i = T.size() - 1; i >= 0; --i)
        {
            while (!s.empty() && T[i] >= T[s.top()])
                s.pop();

            v[i] = s.empty() ? 0 : s.top() - i;
            s.push(i);
        }

        return v;
    }
};
