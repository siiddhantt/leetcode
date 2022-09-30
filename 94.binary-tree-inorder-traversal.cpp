/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    void inorder(TreeNode *root, vector<int> &res)
    {
        if (root->left)
        {
            inorder(root->left, res);
        }
        res.push_back(root->val);
        if (root->right)
        {
            inorder(root->right, res);
        }
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> res;
        inorder(root, res);
        return res;
    }
};
// @lc code=end
