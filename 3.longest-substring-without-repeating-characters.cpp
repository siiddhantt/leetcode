/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
		int n = s.size(), l = 0, r = 0, ans = 0;
		while (r < n) {
			while (r < n && m.find(s[r]) == m.end())
				m[s[r++]]++;
			ans = max(ans, r - l);
			m.erase(s[l++]);
		}
		return ans;
	}
};
// @lc code=end
