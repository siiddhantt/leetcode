/*
 * @lc app=leetcode id=1038 lang=cpp
 *
 * [1038] Binary Search Tree to Greater Sum Tree
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
    void gst(TreeNode *&node, int &s)
    {
        if (node->right)
            gst(node->right, s);
        s += node->val;
        node->val = s;
        if (node->left)
            gst(node->left, s);
    }
    TreeNode *bstToGst(TreeNode *root)
    {
        int s = 0;
        gst(root, s);
        return root;
    }
};
// @lc code=end
