/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:

Input: root = [1,null,2,3]
Output: [1,3,2]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
Example 4:

Input: root = [1,2]
Output: [2,1]
Example 5:

Input: root = [1,null,2]
Output: [1,2]

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

Follow up:

Recursive solution is trivial, could you do it iteratively?
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// Recursive
class Solution
{
public:
    vector<int> v;
    void fn(TreeNode *root)
    {
        if (root == NULL)
            return;
        fn(root->left);
        v.push_back(root->val);
        fn(root->right);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        fn(root);
        return v;
    }
};

// Iterative
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> v;
        stack<TreeNode *> s;
        TreeNode *current = root;
        while (current != NULL || !s.empty())
        {
            while (current != NULL)
            {
                s.push(current);
                current = current->left;
            }
            current = s.top()->right;
            v.push_back(s.top()->val);
            s.pop();
        }
        return v;
    }
};