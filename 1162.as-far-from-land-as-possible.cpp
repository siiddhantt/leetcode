/*
 * @lc app=leetcode id=1162 lang=cpp
 *
 * [1162] As Far from Land as Possible
 */

// @lc code=start
class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        int n = grid.size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                }
            }
        }
        if (q.empty() == true || q.size() == (n * n))
        {
            return -1;
        }
        int val = 1;
        int delr[] = {0, 1, 0, -1}, delc[] = {-1, 0, 1, 0};
        vector<vector<int>> vis(n, vector<int>(n, 0));
        while (!q.empty())
        {
            int r = q.front().first, c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int newr = r + delr[i], newc = c + delc[i];
                if (newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 0)
                {
                    if (vis[newr][newc] >= 1)
                    {
                        vis[newr][newc] = min(vis[newr][newc], vis[r][c] + 1);
                        continue;
                    }
                    q.push({newr, newc});
                    vis[newr][newc] = vis[r][c] + 1;
                }
            }
        }
        int res;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    res = vis[i][j];
                }
                else
                {
                    res = max(res, vis[i][j]);
                }
            }
        }
        return res;
    }
};
// @lc code=end
