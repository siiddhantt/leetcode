/*
 * @lc app=leetcode id=2095 lang=cpp
 *
 * [2095] Delete the Middle Node of a Linked List
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
    ListNode *deleteMiddle(ListNode *head)
    {
        int cou = 0;
        ListNode *node = new ListNode();
        node->next = head;
        while (node->next)
        {
            cou++;
            node->next = node->next->next;
        }
        if (cou == 1)
            return NULL;
        int m = cou / 2;
        node->next = head;
        for (int i = 0; i <= m; i++)
        {
            if (i == m - 1)
                node->next->next = node->next->next->next;
            else
                node->next = node->next->next;
        }
        return head;
    }
};
// @lc code=end
