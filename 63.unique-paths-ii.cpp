/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[m - 1][n - 1] == 1)
            return 0;
        if (m == 1 && n == 1)
            return 1;
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = -1;
        for (int i = m - 2; i >= 0; i--)
        {
            if (dp[i][n - 1] == -1)
                break;
            dp[i][n - 1] = 1;
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (dp[m - 1][i] == -1)
                break;
            dp[m - 1][i] = 1;
        }
        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = n - 2; j >= 0; j--)
            {
                if (dp[i][j] == -1)
                    continue;
                int rc = j + 1, dr = i + 1;
                if (rc < n)
                    if (dp[i][rc] > 0)
                        dp[i][j] += dp[i][rc];
                if (dr < m)
                    if (dp[dr][j] > 0)
                        dp[i][j] += dp[dr][j];
            }
        }
        if (dp[0][0] < 0)
            return 0;
        return dp[0][0];
    }
};
// @lc code=end
