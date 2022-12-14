/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    void preorder(TreeNode *root, vector<int> &res)
    {
        res.push_back(root->val);
        if (root->left)
        {
            preorder(root->left, res);
        }
        if (root->right)
        {
            preorder(root->right, res);
        }
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> res;
        preorder(root, res);
        return res;
    }
};
// @lc code=end
