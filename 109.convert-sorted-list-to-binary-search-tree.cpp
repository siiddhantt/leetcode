/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
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
    TreeNode *rec(vector<int> &vec, int i, int j)
    {
        int m;
        (i + j) % 2 == 0 ? m = (i + j) / 2 : m = (i + j + 1) / 2;
        int l = m - 1, r = m + 1;
        TreeNode *node = new TreeNode(vec[m]);
        if (l >= i && l <= j)
            node->left = rec(vec, i, l);
        if (r >= i && r <= j)
            node->right = rec(vec, r, j);
        return node;
    }
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (!head)
            return NULL;
        vector<int> vec;
        ListNode *node = new ListNode();
        node->next = head;
        while (node->next)
        {
            vec.push_back(node->next->val);
            node->next = node->next->next;
        }
        return rec(vec, 0, vec.size() - 1);
    }
};
// @lc code=end
