/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
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
    vector<int> largestValues(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> ans;
        map<int, int> m;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            TreeNode *node = p.first;
            int lvl = p.second;
            if (node->left)
                q.push({node->left, lvl + 1});
            if (node->right)
                q.push({node->right, lvl + 1});
            if (m.find(lvl) == m.end())
                m[lvl] = node->val;
            else
                m[lvl] = max(m[lvl], node->val);
        }
        for (auto it : m)
            ans.push_back(it.second);
        return ans;
    }
};
// @lc code=end
