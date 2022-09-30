/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
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
        if (n == 1)
        {
            return nums[0];
        }
        vector<int> dp(n - 1, -1);
        vector<int> dp1(n - 1, -1);
        int res1 = subsequence(n - 2, nums, dp);
        vector<int> subv = {nums.begin() + 1, nums.end()};
        int res2 = subsequence(n - 2, subv, dp1);
        return max(res1, res2);
    }
};
// @lc code=end
