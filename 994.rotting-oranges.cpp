/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
class Solution
{
public:
    int rot(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &ans)
    {
        int m = grid.size(), n = grid[0].size(), cou = 0;
        int delr[] = {0, 1, 0, -1}, delc[] = {1, 0, -1, 0};
        for (int i = 0; i < 4; i++)
        {
            int newr = r + delr[i];
            int newc = c + delc[i];
            if (newr >= 0 && newr < m && newc >= 0 && newc < n && grid[newr][newc] == 1 && ans[newr][newc] != 2)
            {
                ans[newr][newc] = 2;
                cou++;
            }
        }
        return cou;
    }

    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), cfresh = 0, ftime = 0;
        vector<vector<int>> ans = grid;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    cfresh += 1;
                }
            }
        }
        if (cfresh == 0)
        {
            return 0;
        }
        while (cfresh > 0)
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] == 2)
                    {
                        int tmp = rot(i, j, grid, ans);
                        cfresh -= tmp;
                    }
                }
            }
            grid = ans;
            ftime++;
            if (ftime > (m * n))
            {
                return -1;
            }
        }
        return ftime;
    }
};
// @lc code=end
