/*
 * @lc app=leetcode id=623 lang=cpp
 *
 * [623] Add One Row to Tree
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
    void add(TreeNode *node, int &val, int &depth, int curr_d)
    {
        curr_d += 1;
        if (curr_d == depth - 1)
        {
            if (node->left)
            {
                auto l = node->left;
                node->left = new TreeNode(val);
                node->left->left = l;
            }
            else
            {
                node->left = new TreeNode(val);
            }
            if (node->right)
            {
                auto r = node->right;
                node->right = new TreeNode(val);
                node->right->right = r;
            }
            else
            {
                node->right = new TreeNode(val);
            }
            return;
        }
        if (node->left)
            add(node->left, val, depth, curr_d);
        if (node->right)
            add(node->right, val, depth, curr_d);
    }
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *n = new TreeNode(val);
            n->left = root;
            return n;
        }
        add(root, val, depth, 0);
        return root;
    }
};
// @lc code=end
