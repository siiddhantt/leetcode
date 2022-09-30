/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<pair<TreeNode *, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> m;
        q.push({root, {0, 0}});
        while (!q.empty())
        {
            auto tmp = q.front();
            q.pop();
            TreeNode *node = tmp.first;
            int i = tmp.second.first, j = tmp.second.second;
            m[i][j].insert(node->val);

            if (node->left)
            {
                q.push({node->left, {i - 1, j + 1}});
            }

            if (node->right)
            {
                q.push({node->right, {i + 1, j + 1}});
            }
        }
        for (auto it : m)
        {
            vector<int> vec;
            for (auto ptr : it.second)
            {
                vec.insert(vec.end(), ptr.second.begin(), ptr.second.end());
            }
            ans.push_back(vec);
        }
        return ans;
    }
};
// @lc code=end
