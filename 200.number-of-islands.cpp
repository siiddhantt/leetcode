/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution
{
public:
    void dfs(int r, int c, vector<vector<char>> &grid, vector<vector<char>> &ans)
    {
        int m = grid.size(), n = grid[0].size();
        int delr[] = {-1, 0, 1, 0}, delc[] = {0, 1, 0, -1};
        ans[r][c] = '0';
        for (int i = 0; i < 4; i++)
        {
            int newr = r + delr[i], newc = c + delc[i];
            if ((newr >= 0 && newr < m) && (newc >= 0 && newc < n) && (grid[newr][newc] == '1') && (ans[newr][newc] != '0'))
            {
                dfs(newr, newc, grid, ans);
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int cou = 0;
        vector<vector<char>> ans = grid;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (ans[i][j] == '0')
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
