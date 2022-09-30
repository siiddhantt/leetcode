/*
 * @lc app=leetcode id=1351 lang=cpp
 *
 * [1351] Count Negative Numbers in a Sorted Matrix
 */

// @lc code=start
class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), cou = 0;
        for (int i = 0; i < m; i++)
        {
            int l = 0, r = n - 1, res = -1;
            while (l <= r)
            {
                int mid = l + ((r - l) / 2);
                if (grid[i][mid] < 0)
                {
                    res = mid;
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            if (res != -1)
            {
                cou += (n - res);
            }
        }
        return cou;
    }
};
// @lc code=end
