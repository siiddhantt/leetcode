/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution
{
public:
    int rec(int i, int stck, vector<int> &prices, vector<int> &dp1, vector<int> &dp2)
    {
        if (i >= prices.size())
            return 0;
        if (i == prices.size() - 1)
        {
            if (stck)
                return prices[i];
            return 0;
        }
        if (!stck)
        {
            if (dp1[i] != -1)
                return dp1[i];
            return dp1[i] = max(rec(i + 1, 1, prices, dp1, dp2) - prices[i], rec(i + 1, 0, prices, dp1, dp2));
        }
        else
        {
            if (dp2[i] != -1)
                return dp2[i];
            return dp2[i] = max(rec(i + 2, 0, prices, dp1, dp2) + prices[i], rec(i + 1, 1, prices, dp1, dp2));
        }
        return 0;
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 1)
            return 0;
        vector<int> dp1(n, -1), dp2(n, -1);
        rec(0, 0, prices, dp1, dp2);
        return max(dp1[0], dp2[0]);
    }
};
// @lc code=end
