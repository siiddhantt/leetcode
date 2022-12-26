/*
 * @lc app=leetcode id=1706 lang=cpp
 *
 * [1706] Where Will the Ball Fall
 */

// @lc code=start
class Solution
{
public:
    vector<int> findBall(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            int col = i + grid[m - 1][i];
            if (col >= 0 && col < n)
                if (grid[m - 1][col] == grid[m - 1][i])
                    dp[m - 1][i] = col;
        }
        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                int col = j + grid[i][j];
                if (col >= 0 && col < n)
                    if (grid[i][col] == grid[i][j])
                        dp[i][j] = dp[i + 1][col];
            }
        }
        return dp[0];
    }
};
// @lc code=end
