/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode *odd = new ListNode();
        ListNode *eve = new ListNode();
        ListNode *eveh = new ListNode();
        if (!head || !head->next)
            return head;
        odd->next = head;
        eve->next = head->next;
        eveh = eve->next;
        while (eve->next && eve->next->next)
        {
            odd->next->next = odd->next->next->next;
            eve->next->next = eve->next->next->next;
            odd->next = odd->next->next;
            eve->next = eve->next->next;
        }
        odd->next->next = eveh;
        return head;
    }
};
// @lc code=end
