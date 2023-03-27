/*
 * @lc app=leetcode id=2304 lang=cpp
 *
 * [2304] Minimum Path Cost in a Grid
 */

// @lc code=start
class Solution
{
public:
    int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost)
    {
        int m = grid.size(), n = grid[0].size();
        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                int s = INT_MAX;
                int val = grid[i][j];
                for (int k = 0; k < n; k++)
                    s = min(s, grid[i + 1][k] + moveCost[val][k]);
                grid[i][j] += s;
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
            ans = min(ans, grid[0][i]);
        return ans;
    }
};
// @lc code=end
