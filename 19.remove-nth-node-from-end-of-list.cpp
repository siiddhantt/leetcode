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
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *iter = head;
        int cou = 0, pos;
        while (iter != NULL)
        {
            cou++;
            iter = iter->next;
        }
        if (cou == 1 && n == 1)
        {
            return NULL;
        }
        pos = cou - n;
        iter = head;
        for (int i = 0; i <= pos; i++)
        {
            if (n == 1 && i == pos - 1)
            {
                iter->next = NULL;
                break;
            }
            if (i == pos)
            {
                iter->val = iter->next->val;
                iter->next = iter->next->next;
                break;
            }
            iter = iter->next;
        }
        return head;
    }
};
// @lc code=end
