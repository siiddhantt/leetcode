/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
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
    ListNode *detectCycle(ListNode *head)
    {
        if (!head)
            return NULL;
        else if (!head->next)
            return NULL;
        int i = 0;
        map<ListNode *, int> m;
        ListNode *curr = head;
        while (m.find(curr) == m.end())
        {
            m[curr] = i++;
            curr = curr->next;
            if (curr == NULL)
                return NULL;
        }
        return curr;
    }
};
// @lc code=end
