/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *ptr = new ListNode();
        ListNode *res = ptr;
        ListNode *tmp = head;
        if (tmp != NULL)
        {
            if (tmp->next == NULL)
            {
                return tmp;
            }
        }
        while (tmp != NULL && tmp->next != NULL)
        {
            ptr->next = tmp->next;
            tmp->next = ptr->next->next;
            ptr->next->next = tmp;
            ptr = tmp;
            tmp = tmp->next;
        }
        return res->next;
    }
};
// @lc code=end
