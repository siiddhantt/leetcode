/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    int idx = 0;
    unordered_map<int, int> m;
    TreeNode *rec(int i, int j, vector<int> &preorder)
    {
        if (i > j)
            return NULL;
        int val = preorder[idx++];
        TreeNode *node = new TreeNode(val);
        if (i == j)
            return node;
        node->left = rec(i, m[val] - 1, preorder);
        node->right = rec(m[val] + 1, j, preorder);
        return node;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = inorder.size();
        for (int i = 0; i < n; i++)
            m[inorder[i]] = i;
        return rec(0, n - 1, preorder);
    }
};
// @lc code=end
