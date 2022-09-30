/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            auto tmp = q.front();
            TreeNode *node = tmp.first;
            int i = tmp.second;
            q.pop();
            if (node->left)
            {
                node->left->val += node->val;
                q.push({node->left, i + 1});
            }
            if (node->right)
            {
                node->right->val += node->val;
                q.push({node->right, i + 1});
            }
            if (!node->left && !node->right)
            {
                if (node->val == targetSum)
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end
