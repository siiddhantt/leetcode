/*
 * @lc app=leetcode id=1026 lang=cpp
 *
 * [1026] Maximum Difference Between Node and Ancestor
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
    int ans = INT_MIN;
    vector<int> anc;
    void dfs(TreeNode *node)
    {
        if (!node)
            return;
        for (auto i : anc)
            ans = max(ans, abs(i - node->val));
        anc.push_back(node->val);
        if (node->left)
            dfs(node->left);
        if (node->right)
            dfs(node->right);
        anc.pop_back();
    }
    int maxAncestorDiff(TreeNode *root)
    {
        dfs(root);
        return ans;
    }
};
// @lc code=end
