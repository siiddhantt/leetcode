/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int t) {
		vector<int> ans(2, 0);
		unordered_map<int, int> m;
		for (int i = 0; i < nums.size(); i++) {
			if (m.find(nums[i]) != m.end()) {
				ans[0] = m[nums[i]];
				ans[1] = i;
				break;
			}
			else
				m[t - nums[i]] = i;
		}
		return ans;
	}
};
// @lc code=end

