/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
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
    void invert(TreeNode *&root)
    {
        if (!root)
            return;
        TreeNode *tmp = new TreeNode();
        tmp->left = root->left;
        root->left = root->right;
        root->right = tmp->left;
        invert(root->left);
        invert(root->right);
    }
    TreeNode *invertTree(TreeNode *root)
    {
        invert(root);
        return root;
    }
};
// @lc code=end
