/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution
{
public:
    int countWays(int n, vector<int> &dp)
    {
        if (dp[n] != -1)
        {
            return dp[n];
        }
        if (n == 0 || n == 1)
        {
            return 1;
        }
        int l = countWays(n - 1, dp);
        int r = countWays(n - 2, dp);
        dp[n] = l + r;
        return (l + r);
    }
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        return countWays(n, dp);
    }
};
// @lc code=end
