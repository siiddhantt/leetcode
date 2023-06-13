/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		// Boyer-Moore Voting Algorithm
		vector<int> ans;
		int n = nums.size(), cou1 = 0, cou2 = 0, el1 = INT_MIN, el2 = INT_MIN;
		for (int i = 0; i < n; i++) {
			if (el1 == nums[i])
				cou1++;
			else if (el2 == nums[i])
				cou2++;
			else if (cou1 == 0) {
				el1 = nums[i];
				cou1++;
			}
			else if (cou2 == 0) {
				el2 = nums[i];
				cou2++;
			}
			else {
				cou1--;
				cou2--;
			}
		}
		cou1 = 0; cou2 = 0;
		for (auto it : nums) {
			if (it == el1)
				cou1++;
			if (it == el2)
				cou2++;
		}
		if (cou1 > n / 3)
			ans.push_back(el1);
		if (cou2 > n / 3 && el1 != el2)
			ans.push_back(el2);
		return ans;
	}
};
// @lc code=end

