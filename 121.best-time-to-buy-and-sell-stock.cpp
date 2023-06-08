/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size(), cmin = prices[0], ans = 0;
		for (int i = 0; i < n; i++) {
			if (prices[i] < cmin)
				cmin = prices[i];
			else
				ans = max(ans, prices[i] - cmin);
		}
		return ans;
	}
};
// @lc code=end
