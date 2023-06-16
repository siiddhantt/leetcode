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
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int c = 0;
		ListNode* tmp = new ListNode(); ListNode* sum = tmp;
		while (l1 != NULL || l2 != NULL) {
			int d = 0;
			if (l1 == NULL) {
				d = l2->val + c;
				l2 = l2->next;
			}
			else if (l2 == NULL) {
				d = l1->val + c;
				l1 = l1->next;
			}
			else {
				d = l1->val + l2->val + c;
				l1 = l1->next;
				l2 = l2->next;
			}
			if (d >= 10) {
				d -= 10;
				c = 1;
			}
			else
				c = 0;
			tmp->next = new ListNode(d);
			tmp = tmp->next;
		}
		if (c == 1)
			tmp->next = new ListNode(1);
		return sum->next;
	}
};
// @lc code=end
