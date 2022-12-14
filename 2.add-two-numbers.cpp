/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *res = new ListNode();
        ListNode *tmp = res;
        int c = 0;
        while (l1 != NULL || l2 != NULL || c != 0)
        {
            int s = 0;
            if (l1 != NULL)
            {
                s += (l1->val);
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                s += (l2->val);
                l2 = l2->next;
            }
            s += c;
            c = s / 10;
            s = s % 10;
            tmp->next = new ListNode(s);
            tmp = tmp->next;
        }
        return res->next;
    }
};
// @lc code=end
