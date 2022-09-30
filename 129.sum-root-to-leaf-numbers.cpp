/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    void path(TreeNode *root, vector<vector<int>> &res, vector<int> &tmp)
    {
        tmp.push_back(root->val);
        if (!root->left && !root->right)
        {
            res.push_back(tmp);
            tmp.pop_back();
            return;
        }
        if (root->left)
        {
            path(root->left, res, tmp);
        }
        if (root->right)
        {
            path(root->right, res, tmp);
        }
        if (tmp.size() > 1)
        {
            tmp.pop_back();
        }
    }
    int sumNumbers(TreeNode *root)
    {
        if (!root)
            return {};
        vector<vector<int>> res;
        vector<int> tmp;
        int ans;
        path(root, res, tmp);
        for (auto i : res)
        {
            int s = 0;
            for (auto j : i)
            {
                s = (s * 10) + j;
            }
            ans += s;
        }
        return ans;
    }
};
// @lc code=end
