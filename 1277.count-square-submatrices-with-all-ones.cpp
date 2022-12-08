/*
 * @lc app=leetcode id=1277 lang=cpp
 *
 * [1277] Count Square Submatrices with All Ones
 */

// @lc code=start
class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size(), cou = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            if (i == 0)
            {
                for (int j = 0; j < n; j++)
                {
                    dp[i][j] = matrix[i][j];
                }
            }
            else
            {
                dp[i][0] = matrix[i][0];
            }
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 1)
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cou += dp[i][j];
            }
        }
        return cou;
    }
};
// @lc code=end
