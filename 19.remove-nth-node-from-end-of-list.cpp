/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int cou = 1;
		ListNode* iter1 = head; ListNode* iter2 = NULL;
		while (iter1) {
			if (iter2)
				iter2 = iter2->next;
			if (cou == n + 1)
				iter2 = head;
			iter1 = iter1->next;
			cou++;
		}
		if (iter2)
			iter2->next = iter2->next->next;
		else
			return head->next;
		return head;
	}
};
// @lc code=end
