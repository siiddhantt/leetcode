/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int n = nums.size();
		vector<vector<int>> ans;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n - 2; i++) {
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			int m = i + 1, j = n - 1;
			while (j > m) {
				int s = nums[i] + nums[m] + nums[j];
				if (s < 0)
					m++;
				else if (s > 0)
					j--;
				else {
					ans.push_back({nums[i], nums[m], nums[j]});
					while (m < n - 1 && nums[m] == nums[m + 1])
						m++;
					m++;
					while (j > i && nums[j] == nums[j - 1])
						j--;
					j--;
				}
			}
		}
		return ans;
	}
};
// @lc code=end
