/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution
{
public:
    int subsequence(int ind, vector<int> &ds, vector<int> &dp)
    {
        if (ind < 0)
        {
            return 0;
        }
        if (ind == 0)
        {
            return ds[ind];
        }
        if (dp[ind] != -1)
        {
            return dp[ind];
        }
        int pick = ds[ind] + subsequence(ind - 2, ds, dp);
        int notpick = 0 + subsequence(ind - 1, ds, dp);
        return dp[ind] = max(pick, notpick);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return subsequence(n - 1, nums, dp);
    }
};
// @lc code=end
