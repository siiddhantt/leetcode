/*
 * @lc app=leetcode id=1339 lang=cpp
 *
 * [1339] Maximum Product of Splitted Binary Tree
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
    const unsigned int M = 1000000007;
    long long ans = INT_MIN;
    void psum(TreeNode *node)
    {
        if (!node)
            return;
        if (node->left)
        {
            psum(node->left);
            node->val += node->left->val;
        }
        if (node->right)
        {
            psum(node->right);
            node->val += node->right->val;
        }
    }
    void dfs(TreeNode *node, int anc)
    {
        if (!node)
            return;
        long long p1, p2;
        if (node->left)
        {
            p1 = node->left->val;
            p2 = (node->val - node->left->val) + anc;
            long long tmp = (p1 * p2);
            ans = max(ans, tmp);
            dfs(node->left, node->val - node->left->val + anc);
        }
        if (node->right)
        {
            p1 = node->right->val;
            p2 = (node->val - node->right->val) + anc;
            long long tmp = (p1 * p2);
            ans = max(ans, tmp);
            dfs(node->right, node->val - node->right->val + anc);
        }
    }
    int maxProduct(TreeNode *root)
    {
        psum(root);
        dfs(root, 0);
        return ans % M;
    }
};
// @lc code=end
