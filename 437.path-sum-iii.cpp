/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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
    void path(TreeNode *root, long long csum, int t, map<long long, int> &m, int &cou)
    {
        csum += root->val;
        if (csum == t)
        {
            cou++;
        }
        if (m.find(csum - t) != m.end())
        {
            cou += m[csum - t];
        }
        m[csum] += 1;
        if (!root->left && !root->right)
        {
            m[csum] -= 1;
            csum -= root->val;
            return;
        }
        if (root->left)
        {
            path(root->left, csum, t, m, cou);
        }
        if (root->right)
        {
            path(root->right, csum, t, m, cou);
        }
        m[csum] -= 1;
        csum -= root->val;
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return {};
        int cou = 0;
        map<long long, int> m;
        path(root, 0, targetSum, m, cou);
        return cou;
    }
};
// @lc code=end
