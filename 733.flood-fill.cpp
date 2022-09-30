/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution
{
public:
    void dfs(int r, int c, vector<vector<int>> &image, vector<vector<int>> &ans, int color, int iniColor)
    {
        int m = image.size(), n = image[0].size();
        int delr[] = {-1, 0, 1, 0}, delc[] = {0, 1, 0, -1};
        ans[r][c] = color;
        for (int i = 0; i < 4; i++)
        {
            int newr = r + delr[i], newc = c + delc[i];
            if ((newr >= 0 && newr < m) && (newc >= 0 && newc < n) && (image[newr][newc] == iniColor) && (ans[newr][newc] != color))
            {
                dfs(newr, newc, image, ans, color, iniColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        vector<vector<int>> ans = image;
        int iniColor = image[sr][sc];
        dfs(sr, sc, image, ans, color, iniColor);
        return ans;
    }
};
// @lc code=end
