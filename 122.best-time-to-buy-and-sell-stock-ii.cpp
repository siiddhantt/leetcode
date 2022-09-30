/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution
{
public:
    vector<int> profitCal(vector<int> &prices, int l, int r)
    {
        int prof = 0, sellpos;
        int curr_min = prices[l];
        for (int i = l + 1; i <= r; i++)
        {
            if ((prices[i] - curr_min) > prof)
            {
                sellpos = i;
            }
            prof = max(prices[i] - curr_min, prof);
            curr_min = min(curr_min, prices[i]);
        }
        return {prof, sellpos};
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size(), prof = 0, pos = 0;
        while (pos < n) {
            vector<int> tmp = profitCal(prices, pos, n-1);
            prof += tmp[0];
            pos = tmp[1];
        }
        return prof;
    }
};
// @lc code=end
