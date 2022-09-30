/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int prof = 0;
        int curr_min = prices[0];
        for(int i = 1; i < prices.size(); i++){
            prof = max(prices[i]-curr_min, prof);
            curr_min = min(curr_min, prices[i]);
        }
        return prof;
    }
};
// @lc code=end
