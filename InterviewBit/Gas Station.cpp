#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(const vector<int> &A, const vector<int> &B)
{
    int sum = 0, diff = 0;
    int start = 0;
    for (int i = 0; i < A.size(); i++)
    {
        sum += A[i] - B[i];
        if (sum < 0)
        {
            start = i + 1;
            diff += sum;
            sum = 0;
        }
    }
    if (sum + diff < 0)
        return -1;
    return start;
}

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int sumGas = 0;
    int sumCost = 0;
    int start = 0;
    int tank = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        sumGas += gas[i];
        sumCost += cost[i];
        tank += gas[i] - cost[i];
        if (tank < 0)
        {
            start = i + 1;
            tank = 0;
        }
    }
    if (sumGas < sumCost)
        return -1;
    return start;
}