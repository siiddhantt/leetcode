/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

// @lc code=start
class Solution
{
public:
    int rec(int i, int j, vector<vector<int>> &dp, vector<vector<pair<int, int>>> &adj, int k)
    {
        if (k < 0)
            return 1e7;
        if (i == j)
            return 0;
        if (dp[i][k] != -1)
            return dp[i][k];
        int ans = 1e7, tmp;
        for (auto it : adj[i])
        {
            tmp = it.second + rec(it.first, j, dp, adj, k - 1);
            ans = min(ans, tmp);
        }
        return dp[i][k] = ans;
    }
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> adj(n);
        vector<vector<int>> dp(n, vector<int>(k + 2, -1));
        for (auto it : flights)
            adj[it[0]].push_back({it[1], it[2]});
        int ans = rec(src, dst, dp, adj, k + 1);
        return (ans == 1e7 ? -1 : ans);
    }
};
// @lc code=end
