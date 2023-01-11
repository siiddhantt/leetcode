/*
 * @lc app=leetcode id=1130 lang=cpp
 *
 * [1130] Minimum Cost Tree From Leaf Values
 */

// @lc code=start
class Solution
{
public:
    pair<int, int> rec(int i, int j, vector<int> &arr, vector<vector<pair<int, int>>> &dp)
    {
        if (i == j)
            return {arr[i], 0};
        if (dp[i][j].first != 0)
            return dp[i][j];
        int nodeMax = INT_MIN, nodeSum = INT_MAX;
        for (int k = i; k < j; k++)
        {
            auto lp = rec(i, k, arr, dp);
            auto rp = rec(k + 1, j, arr, dp);
            nodeMax = max(nodeMax, max(lp.first, rp.first));
            nodeSum = min(nodeSum, lp.first * rp.first + lp.second + rp.second);
        }
        return dp[i][j] = {nodeMax, nodeSum};
    }
    int mctFromLeafValues(vector<int> &arr)
    {
        vector<vector<pair<int, int>>> dp(arr.size(), vector<pair<int, int>>(arr.size()));
        auto ans = rec(0, arr.size() - 1, arr, dp);
        return ans.second;
    }
};
// @lc code=end
