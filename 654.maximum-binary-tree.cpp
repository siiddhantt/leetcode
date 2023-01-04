/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
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
    TreeNode *rec(int i, int j, TreeNode *node, vector<int> &nums)
    {
        if (i > j)
            return NULL;
        int mx = nums[i], mxi = i;
        for (int k = i; k <= j; k++)
        {
            if (nums[k] > mx)
            {
                mx = nums[k];
                mxi = k;
            }
        }
        node->val = mx;
        TreeNode *n1 = new TreeNode();
        TreeNode *n2 = new TreeNode();
        node->left = rec(i, mxi - 1, n1, nums);
        node->right = rec(mxi + 1, j, n2, nums);
        return node;
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        TreeNode *node = new TreeNode();
        return rec(0, nums.size() - 1, node, nums);
    }
};
// @lc code=end
