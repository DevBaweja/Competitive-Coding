#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;

    Node(char x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node *convertExpressionUtil(string str, int &i)
{
    Node *root = new Node(str[i]);
    if (i == str.size() - 1)
        return root;
    i++;

    if (str[i] == '?')
    {
        i++;
        root->left = convertExpressionUtil(str, i);
        i++;
        root->right = convertExpressionUtil(str, i);
        return root;
    }
    return root;
}

Node *convertExpression(string str, int i)
{
    return convertExpressionUtil(str, i);
}