/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        queue<pair<TreeNode *, int>> q;
        map<int, vector<int>> m;
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
            else
            {
                if (node->val != -100)
                {
                    TreeNode *l = new TreeNode(-100);
                    q.push({l, i + 1});
                }
            }
            if (node->right)
            {
                q.push({node->right, i + 1});
            }
            else
            {
                if (node->val != -100)
                {
                    TreeNode *r = new TreeNode(-100);
                    q.push({r, i + 1});
                }
            }
            m[i].push_back(node->val);
        }
        for (auto it : m)
        {
            for (int i = 0; i < it.second.size() / 2; i++)
            {
                if (it.second[i] != it.second[it.second.size() - 1 - i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
