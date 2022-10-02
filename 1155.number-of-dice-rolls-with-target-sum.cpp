/*
 * @lc app=leetcode id=1155 lang=cpp
 *
 * [1155] Number of Dice Rolls With Target Sum
 */

// @lc code=start
class Solution
{
public:
    int dp[31][1001];
    int mod = 1e9 + 7;
    int rolls(int n, int k, int t)
    {
        if (t < 0 || n < 0)
            return 0;
        if (n == 0 && t == 0)
            return 1;
        else if ((n == 0 && t != 0) || (t == 0 && n == 0))
            return 0;
        if (dp[n][t] != -1)
            return dp[n][t];
        int ans = 0;
        for (int i = 1; i <= k; i++)
        {
            ans = (ans % mod + rolls(n - 1, k, t - i) % mod) % mod;
        }
        return dp[n][t] = ans;
    }
    int numRollsToTarget(int n, int k, int target)
    {
        memset(dp, -1, sizeof(dp));
        return rolls(n, k, target);
    }
};
// @lc code=end
