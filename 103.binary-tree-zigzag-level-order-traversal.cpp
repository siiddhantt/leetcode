/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        vector<vector<int>> ans;
        queue<pair<TreeNode *, int>> q;
        map<int, vector<int>> m;
        q.push({root, 0});
        while (!q.empty())
        {
            auto tmp = q.front();
            TreeNode *node = tmp.first;
            q.pop();
            int i = tmp.second;
            if (node->left)
            {
                q.push({node->left, tmp.second + 1});
            }
            if (node->right)
            {
                q.push({node->right, tmp.second + 1});
            }
            m[i].push_back(node->val);
        }
        int cou = 1;
        for (auto it : m)
        {
            if (cou % 2 == 0)
            {
                reverse(it.second.begin(), it.second.end());
                ans.push_back(it.second);
                cou++;
                continue;
            }
            ans.push_back(it.second);
            cou++;
        }
        return ans;
    }
};
// @lc code=end
