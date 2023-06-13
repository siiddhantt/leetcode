/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		// Boyer-Moore Voting Algorithm
		int n = nums.size(), cou = 0, curr;
		for (int i = 0; i < n; i++) {
			if (cou == 0) {
				curr = nums[i];
				cou++;
			}
			else if (curr != nums[i])
				cou--;
			else
				cou++;
		}
		return curr;
	}
};
// @lc code=end

