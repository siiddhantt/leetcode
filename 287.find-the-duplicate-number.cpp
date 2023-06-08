/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution {
public:
	bool check(int n, vector<int>& nums) {
		int cou = 0;
		for (auto it : nums)
			if (it <= n)
				cou++;
		if (cou > n)
			return true;
		return false;
	}
	int findDuplicate(vector<int>& nums) {
		int l = 1, r = nums.size();
		while (r - l > 1) {
			int md = l + (r - l) / 2;
			if (check(md, nums))
				r = md;
			else
				l = md + 1;
		}
		if (check(l, nums))
			return l;
		if (check(r, nums))
			return r;
		return -1;
	}
};
// @lc code=end
