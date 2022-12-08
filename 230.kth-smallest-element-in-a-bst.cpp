/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    int ans = 0, cou = 0;
    void inorder(TreeNode *node, int k)
    {
        if (node->left)
            inorder(node->left, k);
        cou++;
        if (cou == k)
        {
            ans = node->val;
            return;
        }
        if (node->right)
            inorder(node->right, k);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        inorder(root, k);
        return ans;
    }
};
// @lc code=end
