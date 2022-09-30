/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
    int maxDepth(TreeNode *root)
    {
        if (!root)
        {
            return {};
        }
        queue<pair<TreeNode *, int>> q;
        map<int, int> m;
        q.push({root, 0});
        while (!q.empty())
        {
            auto tmp = q.front();
            TreeNode *node = tmp.first;
            int i = tmp.second;
            q.pop();
            if (node->left)
            {
                q.push({node->left, i + 1});
            }
            if (node->right)
            {
                q.push({node->right, i + 1});
            }
            m[i] += 1;
        }
        return m.size();
    }
};
// @lc code=end
