#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Bank
{
public:
    vector<ll> balance;
    int size;
    Bank(vector<ll> &balance)
    {
        this->balance = balance;
        this->size = balance.size();
    }

    bool transfer(int account1, int account2, ll money)
    {
        account1--;
        if (account1 < 0 || account1 >= this->size)
            return false;
        account2--;
        if (account2 < 0 || account2 >= this->size)
            return false;

        if (this->balance[account1] < money)
            return false;

        this->balance[account1] -= money;
        this->balance[account2] += money;

        return true;
    }

    bool deposit(int account, ll money)
    {
        account--;
        if (account < 0 || account >= this->size)
            return false;

        this->balance[account] += money;
        return true;
    }

    bool withdraw(int account, ll money)
    {
        account--;
        if (account < 0 || account >= this->size)
            return false;

        if (this->balance[account] < money)
            return false;

        this->balance[account] -= money;
        return true;
    }
};