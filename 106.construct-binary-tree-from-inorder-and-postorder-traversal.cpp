/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    int idx;
    unordered_map<int, int> m;
    TreeNode *rec(int i, int j, vector<int> &postorder)
    {
        if (i > j)
            return NULL;
        int val = postorder[idx--];
        TreeNode *node = new TreeNode(val);
        if (i == j)
            return node;
        node->right = rec(m[val] + 1, j, postorder);
        node->left = rec(i, m[val] - 1, postorder);
        node->val = val;
        return node;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        for (int i = 0; i < n; i++)
            m[inorder[i]] = i;
        idx = n - 1;
        return rec(0, n - 1, postorder);
    }
};
// @lc code=end
