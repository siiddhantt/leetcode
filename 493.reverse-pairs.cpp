/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 */

// @lc code=start
class Solution {
public:
	int ans = 0;
	void count(int l, int r, int md, vector<int>& nums) {
		int lsz = md - l + 1, rsz = r - md;
		vector<int> left(lsz + 1), right(rsz + 1);
		left[lsz] = INT_MAX, right[rsz] = INT_MAX;
		int i = l, j = md + 1;
		for (; i <= md; i++) {
			while (j <= r && nums[i] > 2 * (long long) nums[j])
				j++;
			ans += j - (md + 1);
		}
		for (int i = 0; i < lsz; i++)
			left[i] = nums[l + i];
		for (int i = 0; i < rsz; i++)
			right[i] = nums[md + 1 + i];
		i = 0, j = 0;
		for (int k = l; k <= r; k++) {
			if (i >= lsz & j >= rsz)
				break;
			else if (i >= lsz)
				nums[k] = right[j++];
			else if (j >= rsz)
				nums[k] = left[i++];
			else if (left[i] <= right[j])
				nums[k] = left[i++];
			else
				nums[k] = right[j++];
		}
	}
	void divide(int l, int r, vector<int>& nums) {
		if (l == r)
			return;
		int md = (l + r) / 2;
		divide(l, md, nums);
		divide(md + 1, r, nums);
		count(l, r, md, nums);
	}
	int reversePairs(vector<int>& nums) {
		int n = nums.size();
		divide(0, n - 1, nums);
		return ans;
	}
};
// @lc code=end

