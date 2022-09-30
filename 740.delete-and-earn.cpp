/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// @lc code=start
class Solution
{
public:
    int subsequence(int ind, vector<int> &ds, vector<long int> &dp)
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
            return (dp[ind] * (ind + 1));
        }
        return dp[ind] = max((ds[ind] * (ind + 1)) + subsequence(ind - 2, ds, dp), 0 + subsequence(ind - 1, ds, dp));
    }
    int deleteAndEarn(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(10000, 0);
        vector<long int> dp1(10000, -1);
        for (int i = 0; i < n; i++)
        {
            dp[nums[i] - 1] += 1;
        }
        return subsequence(9999, dp, dp1);
    }
};
// @lc code=end
