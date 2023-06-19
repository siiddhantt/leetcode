/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 */

// @lc code=start
class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int ans = 0, curr = 0;
		for (auto it : nums) {
			if (it == 1)
				curr++;
			else {
				ans = max(ans, curr);
				curr = 0;
			}
		}
		ans = max(ans, curr);
		return ans;
	}
};
// @lc code=end

