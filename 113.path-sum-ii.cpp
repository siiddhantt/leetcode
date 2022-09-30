/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    void path(TreeNode *root, int csum, int t, vector<vector<int>> &res, vector<int> &tmp)
    {
        tmp.push_back(root->val);
        csum += root->val;
        if (!root->left && !root->right)
        {
            if (csum == t)
            {
                res.push_back(tmp);
                csum -= tmp.back();
                tmp.pop_back();
            }
            else
            {
                csum -= tmp.back();
                tmp.pop_back();
            }
            return;
        }
        if (root->left)
        {
            path(root->left, csum, t, res, tmp);
        }
        if (root->right)
        {
            path(root->right, csum, t, res, tmp);
        }
        if (tmp.size() > 1)
        {
            csum -= tmp.back();
            tmp.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return {};
        vector<vector<int>> res;
        vector<int> tmp;
        path(root, 0, targetSum, res, tmp);
        return res;
    }
};
// @lc code=end
