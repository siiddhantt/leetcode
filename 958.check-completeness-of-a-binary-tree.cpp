/*
 * @lc app=leetcode id=958 lang=cpp
 *
 * [958] Check Completeness of a Binary Tree
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
    bool isCompleteTree(TreeNode *root)
    {
        map<int, vector<int>> m;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            TreeNode *node = p.first;
            int l = p.second;
            if (node->left)
                q.push({node->left, l + 1});
            else
            {
                if (node->val != -100)
                {
                    TreeNode *ln = new TreeNode(-100);
                    q.push({ln, l + 1});
                }
            }
            if (node->right)
                q.push({node->right, l + 1});
            else
            {
                if (node->val != -100)
                {
                    TreeNode *rn = new TreeNode(-100);
                    q.push({rn, l + 1});
                }
            }
            m[l].push_back(node->val);
        }
        int flg = 0, lvl = m.rbegin()->first - 1;
        for (int i = 0; i <= lvl; i++)
        {
            for (auto it : m[i])
            {
                if (it < 0 && i < lvl)
                    return false;
                if (i == lvl)
                {
                    if (it == -100)
                        flg = 1;
                    if (it >= 1 && flg == 1)
                        return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
