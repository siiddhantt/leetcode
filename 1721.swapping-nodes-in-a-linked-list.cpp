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
        if (!head->next)
            return head;
        ListNode **ptr = &head;
        ListNode *r = new ListNode();
        int cou = 1;
        auto tmp = *ptr;
        r->next = tmp;
        while (tmp->next != NULL)
        {
            cou++;
            if (cou <= k)
                r->next = tmp->next;
            ptr = &(tmp->next);
            tmp = *ptr;
        }
        int bck = cou - k + 1;
        int diff = bck - k;
        ptr = &(r->next);
        tmp = *ptr;
        ListNode *l = new ListNode();
        l->next = r->next;
        for (int i = 0; i < diff; i++)
        {
            r->next = tmp->next;
            ptr = &(tmp->next);
            tmp = *ptr;
        }
        if (bck < k)
        {
            ptr = &head;
            tmp = *ptr;
            for (int i = 0; i < bck; i++)
            {
                r->next = tmp;
                ptr = &(tmp->next);
                tmp = *ptr;
            }
        }
        int v = l->next->val;
        l->next->val = r->next->val;
        r->next->val = v;
        cout << cou << endl;
        return head;
    }
};
// @lc code=end
