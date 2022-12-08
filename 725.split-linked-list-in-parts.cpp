/*
 * @lc app=leetcode id=725 lang=cpp
 *
 * [725] Split Linked List in Parts
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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        vector<ListNode *> ans(k, NULL);
        int n = 0, pos = 0;
        ListNode *ptr = head;
        while (ptr)
        {
            ptr = ptr->next;
            n++;
        }
        int q = n / k, rem = n % k;
        ptr = head;
        for (int i = 0; i < k; i++)
        {
            int j = q;
            if (rem > 0)
            {
                j = q + 1;
                rem--;
            }
            ListNode *tmp = new ListNode();
            ListNode *tmph = tmp;
            for (int k = 0; k < j; k++)
            {
                if (!ptr)
                    continue;
                ListNode *node = new ListNode(ptr->val);
                tmp->next = node;
                tmp = tmp->next;
                ptr = ptr->next;
            }
            ans[pos] = (tmph->next);
            pos++;
        }
        return ans;
    }
};
// @lc code=end
