/*
 * @lc app=leetcode id=813 lang=cpp
 *
 * [813] Largest Sum of Averages
 */

// @lc code=start
class Solution
{
public:
    double rec(int i, vector<int> &nums, vector<vector<double>> &dp, int k)
    {
        if (i < 0)
            return 0.000000;
        if (k == 0)
            return INT_MIN;
        if (dp[i][k] != -1.000000)
            return dp[i][k];
        int s = 0;
        double ans = INT_MIN, tmp = 0.000000;
        for (int j = i; j >= 0; j--)
        {
            s += nums[j];
            tmp = (double)s / (double)(i + 1 - j);
            tmp += rec(j - 1, nums, dp, k - 1);
            ans = max(ans, tmp);
        }
        return dp[i][k] = ans;
    }
    double largestSumOfAverages(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<vector<double>> dp(n, vector<double>(k + 1, -1.000000));
        return rec(n - 1, nums, dp, k);
    }
};
// @lc code=end
