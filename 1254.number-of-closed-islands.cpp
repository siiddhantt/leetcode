/*
 * @lc app=leetcode id=1254 lang=cpp
 *
 * [1254] Number of Closed Islands
 */

// @lc code=start
class Solution
{
public:
    void dfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &ans)
    {
        int m = grid.size(), n = grid[0].size();
        int delr[] = {-1, 0, 1, 0}, delc[] = {0, 1, 0, -1};
        ans[r][c] = 1;
        for (int i = 0; i < 4; i++)
        {
            int newr = r + delr[i], newc = c + delc[i];
            if ((newr >= 0 && newr < m) && (newc >= 0 && newc < n) && (grid[newr][newc] == 0) && (ans[newr][newc] != 1))
            {
                dfs(newr, newc, grid, ans);
            }
        }
    }
    int closedIsland(vector<vector<int>> &grid)
    {
        int cou = 0, opencou = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans = grid;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (ans[i][j] == 1)
                {
                    continue;
                }
                else
                {
                    if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
                    {
                        dfs(i, j, grid, ans);
                    }
                }
            }
        }
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (ans[i][j] == 1)
                {
                    continue;
                }
                else
                {
                    dfs(i, j, grid, ans);
                    cou++;
                }
            }
        }
        return cou;
    }
};
// @lc code=end
