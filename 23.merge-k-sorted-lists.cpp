/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
class comp
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *ans = new ListNode(0);
        ListNode *head = ans;
        priority_queue<ListNode *, vector<ListNode *>, comp> pq;
        for (auto it : lists)
            if (it != NULL)
                pq.push(it);
        while (!pq.empty())
        {
            auto node = pq.top();
            pq.pop();
            ans->next = node;
            ans = ans->next;
            node = node->next;
            if (node != NULL)
                pq.push(node);
        }
        return head->next;
    }
};
// @lc code=end
