/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    void postorder(TreeNode *root, vector<int> &res)
    {
        if (root->left)
        {
            postorder(root->left, res);
        }
        if (root->right)
        {
            postorder(root->right, res);
        }
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> res;
        postorder(root, res);
        return res;
    }
};
// @lc code=end