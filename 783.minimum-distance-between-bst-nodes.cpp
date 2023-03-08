/*
 * @lc app=leetcode id=783 lang=cpp
 *
 * [783] Minimum Distance Between BST Nodes
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
    vector<int> vec;
    int ans = INT_MAX;
    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        if (root->left)
            inorder(root->left);
        if (vec.size() != 0)
            ans = min(ans, root->val - vec.back());
        vec.push_back(root->val);
        if (root->right)
            inorder(root->right);
    }
    int minDiffInBST(TreeNode *root)
    {
        inorder(root);
        return ans;
    }
};
// @lc code=end
