/*
 * @lc app=leetcode id=1043 lang=cpp
 *
 * [1043] Partition Array for Maximum Sum
 */

// @lc code=start
class Solution
{
public:
    int rec(vector<int> &arr, int k, int i, vector<int> &dp)
    {
        if (i >= arr.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int mx = INT_MIN, maxs = 0, l = 0;
        for (int j = i; j < min(int(arr.size()), i + k); j++)
        {
            l++;
            mx = max(mx, arr[j]);
            int tmp = (l * mx) + rec(arr, k, j + 1, dp);
            maxs = max(maxs, tmp);
        }
        return dp[i] = maxs;
    }
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        vector<int> dp(arr.size(), -1);
        return rec(arr, k, 0, dp);
    }
};
// @lc code=end
