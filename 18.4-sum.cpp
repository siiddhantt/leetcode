/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
#define ll long long
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int t) {
		int n = nums.size();
		vector<vector<int>> ans;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n - 3; i++) {
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			for (int k = i + 1; k < n - 2; k++) {
				if (k > i + 1 && nums[k] == nums[k - 1])
					continue;
				int m = k + 1, j = n - 1;
				while (j > m) {
					ll s = (ll)nums[i] + (ll)nums[k] + (ll)nums[m] + (ll)nums[j];
					if (s < t)
						m++;
					else if (s > t)
						j--;
					else {
						ans.push_back({nums[i], nums[k], nums[m], nums[j]});
						while (m < n - 1 && nums[m] == nums[m + 1])
							m++;
						m++;
						while (j > i && nums[j] == nums[j - 1])
							j--;
						j--;
					}
				}
			}
		}
		return ans;
	}
};
// @lc code=end

