/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 */

// @lc code=start
class Solution
{
public:
    void dfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &ans, int &cou)
    {
        int m = grid.size(), n = grid[0].size();
        ans[r][c] = 0;
        cou++;
        int delr[] = {0, 1, 0, -1}, delc[] = {-1, 0, 1, 0};
        for (int i = 0; i < 4; i++)
        {
            int newr = r + delr[i];
            int newc = c + delc[i];
            if (newr >= 0 && newr < m && newc >= 0 && newc < n && grid[newr][newc] == 1 && ans[newr][newc] != 0)
            {
                dfs(newr, newc, grid, ans, cou);
            }
        }
    }
    int numEnclaves(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), cou = 0, icou = 0;
        vector<vector<int>> ans = grid;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && (ans[i][j] == 1))
                {
                    dfs(i, j, grid, ans, cou);
                }
            }
        }
        cou = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (ans[i][j] == 1)
                {
                    dfs(i, j, grid, ans, cou);
                }
            }
        }
        return cou;
    }
};
// @lc code=end
