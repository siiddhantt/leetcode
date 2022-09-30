/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start
class Solution
{
public:
    bool dfs(int r, int c, vector<vector<int>> &heights, vector<vector<int>> &vis, int &cour, int &couc, vector<vector<pair<int, int>>> &dp)
    {
        int m = heights.size(), n = heights[0].size();
        vis[r][c] = 1;
        if ((r == 0 && c == n - 1) || (r == m - 1 && c == 0))
        {
            return true;
        }
        if(dp[r][c].first >= 1 & dp[r][c].second >= 1) {
            return true;
        }
        if(dp[r][c].first != 0 || dp[r][c].second != 0) {
            cour = dp[r][c].first;
            couc = dp[r][c].second;
        }
        if (cour > 0 && couc > 0)
        {
            cour = 0, couc = 0;
            return true;
        }
        int delr[] = {0, 1, 0, -1}, delc[] = {-1, 0, 1, 0};
        for (int i = 0; i < 4; i++)
        {
            int newr = r + delr[i], newc = c + delc[i];
            if (newr >= 0 && newr < m && newc >= 0 && newc < n && (heights[newr][newc] <= heights[r][c]) && vis[newr][newc] != 1)
            {
                if (dfs(newr, newc, heights, vis, cour, couc, dp) == true)
                {
                    return true;
                }
                continue;
            }
            else if (newr < 0 || newr >= m || newc < 0 || newc >= n)
            {
                if (r == 0 || c == 0)
                {
                    cour++;
                }
                if (r == m - 1 || c == n - 1)
                {
                    couc++;
                }
            }
        }
        dp[r][c] = {cour, couc};
        if (cour > 0 && couc > 0)
        {
            cour = 0, couc = 0;
            return true;
        }
        return false;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> res;
        vector<vector<pair<int, int>>> dp(m, vector<pair<int, int>>(n, {0, 0}));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                vector<vector<int>> vis(m, vector<int>(n, 0));
                int cour = 0, couc = 0;
                if (dfs(i, j, heights, vis, cour, couc, dp))
                {
                    res.push_back({i, j});
                    dp[i][j] = {1, 1};
                }
            }
        }
        return res;
    }
};
// @lc code=end
