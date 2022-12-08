/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
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
    void sumBST(TreeNode *node, int &low, int &high, int &s)
    {
        if (node->left)
            sumBST(node->left, low, high, s);
        if (node->val >= low && node->val <= high)
            s += node->val;
        if (node->right)
            sumBST(node->right, low, high, s);
    }
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        int s = 0;
        sumBST(root, low, high, s);
        return s;
    }
};
// @lc code=end
