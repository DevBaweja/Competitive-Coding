#include <bits/stdc++.h>
#include <string>
using namespace std;

struct node
{
    string data;
    node *left;
    node *right;
};

int getValue(int a, int b, string op)
{
    if (op == "+")
        return a + b;
    if (op == "-")
        return a - b;
    if (op == "*")
        return a * b;
    if (op == "/")
        return a / b;
}
int evalTree(node *root)
{
    if (!root)
        0;
    if (!root->left && !root->right)
        return stoi(root->data);
    string temp = root->data;
    int lsum = evalTree(root->left);
    int rsum = evalTree(root->right);
    return getValue(lsum, rsum, temp);
}