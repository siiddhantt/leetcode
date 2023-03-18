/*
 * @lc app=leetcode id=988 lang=cpp
 *
 * [988] Smallest String Starting From Leaf
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
    void rec(TreeNode *node, vector<string> &vec, string &tmp)
    {
        char c = 'a' + node->val;
        tmp = c + tmp;
        if (!node->right && !node->left)
        {
            vec.push_back(tmp);
            tmp.erase(0, 1);
            return;
        }
        if (node->left)
            rec(node->left, vec, tmp);
        if (node->right)
            rec(node->right, vec, tmp);
        if (tmp.size() > 1)
            tmp.erase(0, 1);
    }
    string smallestFromLeaf(TreeNode *root)
    {
        if (!root)
            return "";
        string tmp = "";
        vector<string> vec;
        rec(root, vec, tmp);
        sort(vec.begin(), vec.end());
        return vec.front();
    }
};
// @lc code=end
