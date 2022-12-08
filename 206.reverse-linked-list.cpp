/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    void reverse(ListNode *node, ListNode *&ptr, ListNode *pnode)
    {
        if (!node->next)
        {
            node->next = pnode;
            ptr->next = node;
            return;
        }
        ListNode *tmp = new ListNode();
        tmp = node->next;
        node->next = pnode;
        reverse(tmp, ptr, node);
    }
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
            return NULL;
        ListNode *ptr = new ListNode();
        reverse(head, ptr, NULL);
        return ptr->next;
    }
};
// @lc code=end
