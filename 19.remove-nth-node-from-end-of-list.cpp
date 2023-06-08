/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *curr = new ListNode(head->val, head->next);
        ListNode *node = curr;
        ListNode *right = curr;
        ListNode *prev = NULL;
        int i = 1;
        while (curr != NULL)
        {
            if (i > n)
            {
                prev = right;
                right = right->next;
            }
            curr = curr->next;
            i++;
        }
        if (!prev)
            return right->next;
        else
            prev->next = right->next;
        return node;
    }
};
// @lc code=end
