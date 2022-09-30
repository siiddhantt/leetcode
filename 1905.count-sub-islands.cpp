/*
 * @lc app=leetcode id=1905 lang=cpp
 *
 * [1905] Count Sub Islands
 */

// @lc code=start
class Solution
{
public:
    void dfs(int r, int c, vector<vector<int>> &grid1, vector<vector<int>> &grid2, vector<vector<int>> &ans, bool &state)
    {
        int m = grid2.size(), n = grid2[0].size();
        if (ans[r][c] != grid1[r][c])
        {
            state = false;
        }
        ans[r][c] = 0;
        int delr[] = {0, 1, 0, -1}, delc[] = {-1, 0, 1, 0};
        for (int i = 0; i < 4; i++)
        {
            int newr = r + delr[i];
            int newc = c + delc[i];
            if (newr >= 0 && newr < m && newc >= 0 && newc < n && grid2[newr][newc] == 1 && ans[newr][newc] != 0)
            {
                dfs(newr, newc, grid1, grid2, ans, state);
            }
        }
    }
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int m = grid2.size(), n = grid2[0].size(), cou = 0;
        vector<vector<int>> ans = grid2;
        bool state;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (ans[i][j] != 0)
                {
                    state = true;
                    dfs(i, j, grid1, grid2, ans, state);
                    if (state == true)
                    {
                        cou++;
                    }
                }
            }
        }
        return cou;
    }
};
// @lc code=end
