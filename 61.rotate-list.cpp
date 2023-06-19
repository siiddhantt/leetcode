/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 */

// @lc code=start
#define ll long long
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
	ListNode* rotateRight(ListNode* head, int k) {
		vector<int> vec;
		ListNode* iter = head;
		while (iter) {
			vec.push_back(iter->val);
			iter = iter->next;
		}
		iter = head;
		int n = vec.size();
		if (k == 0 || n == 0)
			return head;
		ll md = k % n, cou = 1; ll i = n - md;
		while (cou <= n) {
			iter->val = vec[i % n];
			iter = iter->next;
			i++; cou++;
		}
		return head;
	}
};
// @lc code=end

