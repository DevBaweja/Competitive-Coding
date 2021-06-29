#include <bits/stdc++.h>
using namespace std;

struct Node
{
    bool data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

long long unsigned int decimalValue(Node *head)
{
    int MOD = 1e9 + 7;
    if (!head)
        return 0;
    Node *temp = head;
    long long unsigned int res = 0;
    while (temp)
    {
        res = (res << 1) + temp->data;
        res %= MOD;
        temp = temp->next;
    }
    return res;
}