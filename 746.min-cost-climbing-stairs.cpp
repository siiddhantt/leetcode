/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        vector<int> dp(cost.size(), 0);
        dp[0] = cost[0], dp[1] = cost[1];
        for (int i = 2; i < cost.size(); i++)
        {
            dp[i] = cost[i] + min(dp[i - 2], dp[i - 1]);
        }
        return min(dp[cost.size() - 2], dp[cost.size() - 1]);
    }
};
// @lc code=end
