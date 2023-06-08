/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
	void sortColors(vector<int>& nums) {
		multiset<int> st;
		for (auto it : nums)
			st.insert(it);
		int i = 0;
		for (auto it : st) {
			nums[i] = it;
			i++;
		}
	}
};
// @lc code=end
