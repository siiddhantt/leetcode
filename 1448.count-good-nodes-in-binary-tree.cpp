/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
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
    void dfs(TreeNode *root, int cmax, int &res)
    {
        if (!root)
        {
            return;
        }
        if (root->val >= cmax)
        {
            res++;
        }
        dfs(root->left, max(root->val, cmax), res);
        dfs(root->right, max(root->val, cmax), res);
    }
    int goodNodes(TreeNode *root)
    {
        int cmax, res = 0;
        dfs(root, INT_MIN, res);
        return res;
    }
};
// @lc code=end
