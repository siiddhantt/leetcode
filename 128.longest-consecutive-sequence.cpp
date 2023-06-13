/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		int ans = 0;
		unordered_map<int, int> m;
		for (auto it : nums)
			m[it]++;
		for (auto it : m) {
			if (m.find(it.first - 1) != m.end())
				continue;
			else {
				int val = it.first + 1, curr = 1;
				while (m.find(val) != m.end()) {
					curr++;
					val++;
				}
				ans = max(ans, curr);
			}
		}
		return ans;
	}
};
// @lc code=end
