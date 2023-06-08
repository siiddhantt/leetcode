/*
 * @lc app=leetcode id=1721 lang=cpp
 *
 * [1721] Swapping Nodes in a Linked List
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
class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *curr = new ListNode(head->val, head->next);
        ListNode *node = curr;
        ListNode *left = curr;
        ListNode *right = curr;
        int i = 1;
        while (curr != NULL)
        {
            if (i < k)
                left = left->next;
            if (i > k)
                right = right->next;
            curr = curr->next;
            i++;
        }
        int tmp = left->val;
        left->val = right->val;
        right->val = tmp;
        return node;
    }
};
// @lc code=end
