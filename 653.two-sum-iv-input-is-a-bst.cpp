/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
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
    bool ans = false;
    bool target(TreeNode *node, unordered_map<int, int> &m, int t)
    {
        if (m.find(node->val) != m.end())
            return ans = true;
        m[t - node->val] += 1;
        if (node->left)
            target(node->left, m, t);
        if (node->right)
            target(node->right, m, t);
        return false;
    }
    bool findTarget(TreeNode *root, int k)
    {
        unordered_map<int, int> m;
        target(root, m, k);
        if (ans)
            return true;
        else
            return false;
    }
};
// @lc code=end
