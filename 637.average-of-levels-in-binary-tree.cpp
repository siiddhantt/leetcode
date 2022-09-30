/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
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
    vector<double> averageOfLevels(TreeNode *root)
    {
        double avg;
        vector<double> ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            avg = 0.00000;
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                avg += node->val;
                q.pop();
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
                if (i == n - 1)
                {
                    ans.push_back(avg / n);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
