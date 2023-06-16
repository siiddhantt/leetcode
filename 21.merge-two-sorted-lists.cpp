/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode* tmp = new ListNode();
		ListNode* ans = tmp; ListNode* iter1 = list1; ListNode* iter2 = list2;
		while (iter1 != NULL || iter2 != NULL) {
			if (iter1 == NULL) {
				tmp->next = iter2;
				iter2 = iter2->next;
			}
			else if (iter2 == NULL) {
				tmp->next = iter1;
				iter1 = iter1->next;
			}
			else if (iter1->val <= iter2->val) {
				tmp->next = iter1;
				iter1 = iter1->next;
			}
			else {
				tmp->next = iter2;
				iter2 = iter2->next;
			}
			tmp = tmp->next;
		}
		return ans->next;
	}
};
// @lc code=end
