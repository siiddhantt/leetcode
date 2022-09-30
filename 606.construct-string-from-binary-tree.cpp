/*
 * @lc app=leetcode id=606 lang=cpp
 *
 * [606] Construct String from Binary Tree
 */

// @lc code=start
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
class Solution
{
public:
    void preorder(TreeNode *root, string &s)
    {
        s += to_string(root->val);
        s += '(';
        if (root->left)
        {
            preorder(root->left, s);
        }
        if (s[s.length() - 1] == '(' && !root->right)
        {
            s.pop_back();
        }
        else
        {
            s += ')';
        }
        s += '(';
        if (root->right)
        {
            preorder(root->right, s);
        }
        if (s[s.length() - 1] == '(')
        {
            s.pop_back();
        }
        else
        {
            s += ')';
        }
    }
    string tree2str(TreeNode *root)
    {
        string s;
        preorder(root, s);
        return s;
    }
};
// @lc code=end
