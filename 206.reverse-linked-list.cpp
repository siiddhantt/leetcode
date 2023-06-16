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
class Solution {
public:
	ListNode* ans = new ListNode();
	ListNode* rec(ListNode* node) {
		if (node == NULL)
			return ans;
		ListNode* tmp = rec(node->next);
		ListNode* newNode = new ListNode(node->val);
		tmp->next = newNode;
		return newNode;
	}
	ListNode* reverseList(ListNode* head) {
		rec(head);
		return ans->next;
	}
};
// @lc code=end
