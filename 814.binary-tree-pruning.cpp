/*
 * @lc app=leetcode id=814 lang=cpp
 *
 * [814] Binary Tree Pruning
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
    TreeNode *prune(TreeNode *root)
    {
        if (root != NULL)
        {
            root->left = prune(root->left);
            root->right = prune(root->right);
            if (root->left == NULL && root->right == NULL && root->val == 0)
            {
                return NULL;
            }
        }
        return root;
    }
    TreeNode *pruneTree(TreeNode *root)
    {
        return prune(root);
    }
};
// @lc code=end
