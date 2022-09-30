/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        else if ((!p && q) || (p && !q))
            return false;
        queue<TreeNode *> t1, t2;
        t1.push(p);
        t2.push(q);
        while (!t1.empty() || !t2.empty())
        {
            TreeNode *n1 = t1.front();
            TreeNode *n2 = t2.front();
            t1.pop();
            t2.pop();
            if (n1->val != n2->val)
            {
                return false;
            }
            if (n1->left && n2->left)
            {
                t1.push(n1->left);
                t2.push(n2->left);
            }
            if (n1->right && n2->right)
            {
                t1.push(n1->right);
                t2.push(n2->right);
            }
            if ((n1->left && !n2->left) || (!n1->left && n2->left) || (n1->right && !n2->right) || (!n1->right && n2->right))
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
