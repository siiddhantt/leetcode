/*
 * @lc app=leetcode id=799 lang=cpp
 *
 * [799] Champagne Tower
 */

// @lc code=start
class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        double dp[101][101] = {0};
        dp[0][0] = poured;
        for (int i = 0; i <= query_row; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (dp[i][j] > 1)
                {
                    dp[i + 1][j] += (dp[i][j] - 1) / 2;
                    dp[i + 1][j + 1] += (dp[i][j] - 1) / 2;
                    dp[i][j] = min(1.0, dp[i][j]);
                }
            }
        }
        return dp[query_row][query_glass];
    }
};
// @lc code=end
