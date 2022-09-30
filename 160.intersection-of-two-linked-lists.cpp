/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *ptr1 = headA, *ptr2 = headB;
        while (ptr1 != NULL || ptr2 != NULL)
        {
            if (ptr1 == ptr2)
            {
                return ptr1;
            }
            if (ptr1 == NULL)
            {
                ptr1 = headB;
                continue;
            }
            if (ptr2 == NULL)
            {
                ptr2 = headA;
                continue;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return NULL;
    }
};
// @lc code=end
