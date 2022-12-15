/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
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
    void rec(TreeNode *root, vector<int> &ans)
    {
        if (!root->left && !root->right)
            ans.push_back(root->val);
        if (root->left)
            rec(root->left, ans);
        if (root->right)
            rec(root->right, ans);
    }
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> v1, v2;
        rec(root1, v1);
        rec(root2, v2);
        if (v1 == v2)
            return true;
        return false;
    }
};
// @lc code=end
