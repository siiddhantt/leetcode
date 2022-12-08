/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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
    // Inorder traversal of BST gives sorted order traversal
    TreeNode *prev = NULL;
    void getMin(TreeNode *node, int &diff)
    {
        if (node->left)
        {
            getMin(node->left, diff);
        }
        if (prev)
            diff = min(diff, abs(node->val - prev->val));
        prev = node;
        if (node->right)
        {
            getMin(node->right, diff);
        }
    }
    int getMinimumDifference(TreeNode *root)
    {
        int diff = INT_MAX;
        getMin(root, diff);
        return diff;
    }
};
// @lc code=end
