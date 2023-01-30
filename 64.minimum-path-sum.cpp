/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution
{
public:
    int rec(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (i == grid.size() - 1 && j == grid[0].size() - 1)
            return grid[i][j];
        if (i >= grid.size() || j >= grid[0].size())
            return 1e7;
        if (dp[i][j] != -1)
            return dp[i][j];
        int sum = grid[i][j];
        sum += min(rec(i + 1, j, grid, dp), rec(i, j + 1, grid, dp));
        return dp[i][j] = sum;
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return rec(0, 0, grid, dp);
    }
};
// @lc code=end
