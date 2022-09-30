/*
 * @lc app=leetcode id=1302 lang=cpp
 *
 * [1302] Deepest Leaves Sum
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
    int deepestLeavesSum(TreeNode *root)
    {
        if (!root)
            return 0;
        vector<vector<int>> ans;
        queue<pair<TreeNode *, int>> q;
        map<int, vector<int>> m;
        q.push({root, 0});
        while (!q.empty())
        {
            auto tmp = q.front();
            TreeNode *node = tmp.first;
            q.pop();
            if (node->left)
            {
                q.push({node->left, tmp.second + 1});
            }
            if (node->right)
            {
                q.push({node->right, tmp.second + 1});
            }
            int i = tmp.second;
            m[i].push_back(node->val);
        }
        return accumulate((m.rbegin()->second).begin(), (m.rbegin()->second).end(), 0);
    }
};
// @lc code=end
