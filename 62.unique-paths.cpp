/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        if (m == 1 && n == 1)
            return 1;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = m - 2; i >= 0; i--)
            dp[i][n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
            dp[m - 1][i] = 1;
        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = n - 2; j >= 0; j--)
            {
                int rc = j + 1, dr = i + 1;
                if (rc < n)
                    dp[i][j] += dp[i][rc];
                if (dr < m)
                    dp[i][j] += dp[dr][j];
            }
        }
        return dp[0][0];
    }
};
// @lc code=end
