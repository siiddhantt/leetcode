/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 */

// @lc code=start
class Solution
{
public:
    int bfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &vis, int &cou)
    {
        int n = grid.size();
        queue<pair<pair<int, int>, int>> q;
        q.push({{r, c}, cou});
        vis[r][c] = 1;
        int delr[] = {1, 1, -1, -1, 1, 0, -1, 0}, delc[] = {1, -1, 1, -1, 0, 1, 0, -1};
        while (!q.empty())
        {
            r = q.front().first.first, c = q.front().first.second;
            cou = q.front().second;
            q.pop();
            if (r == n - 1 && c == n - 1)
            {
                return cou;
            }
            cou++;
            for (int i = 0; i < 8; i++)
            {
                int newr = r + delr[i], newc = c + delc[i];
                if (newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 0 && vis[newr][newc] != 1)
                {
                    vis[newr][newc] = 1;
                    q.push({{newr, newc}, cou});
                }
                if (newr == n - 1 && newc == n - 1)
                {
                    return (cou + 1);
                }
            }
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size(), cou = 0;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
        {
            return -1;
        }
        if (n == 1 && grid[0][0] == 0)
        {
            return 1;
        }
        int res = bfs(0, 0, grid, vis, cou);
        return res;
    }
};
// @lc code=end
