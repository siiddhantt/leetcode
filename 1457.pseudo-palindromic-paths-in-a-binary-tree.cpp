/*
 * @lc app=leetcode id=1457 lang=cpp
 *
 * [1457] Pseudo-Palindromic Paths in a Binary Tree
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
    unordered_map<int, int> m;
    bool isPPal()
    {
        int flag = 0;
        for (auto i : m)
        {
            if (i.second % 2 == 0)
                continue;
            else if (i.second % 2 != 0 && flag == 0)
            {
                flag++;
                continue;
            }
            else
                return false;
        }
        return true;
    }
    void path(TreeNode *root, vector<int> &tmp, int &cou)
    {
        tmp.push_back(root->val);
        m[root->val] += 1;
        if (root->left)
        {
            path(root->left, tmp, cou);
        }
        if (root->right)
        {
            path(root->right, tmp, cou);
        }
        if (!root->left && !root->right)
        {
            if (isPPal())
                cou++;
            m[tmp.back()] -= 1;
            tmp.pop_back();
            return;
        }
        m[tmp.back()] -= 1;
        tmp.pop_back();
    }
    int pseudoPalindromicPaths(TreeNode *root)
    {
        int cou = 0;
        vector<int> tmp;
        path(root, tmp, cou);
        return cou;
    }
};
// @lc code=end
