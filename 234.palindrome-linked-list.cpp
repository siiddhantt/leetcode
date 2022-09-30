/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    bool isPalindrome(ListNode *head)
    {
        vector<int> vec;
        while (head != NULL)
        {
            ListNode *next = head->next;
            vec.push_back(head->val);
            head = next;
        }
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] == vec[vec.size() - 1 - i])
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
