/*
 * @lc app=leetcode id=2087 lang=cpp
 *
 * [2087] Minimum Cost Homecoming of a Robot in a Grid
 */

// @lc code=start
class Solution
{
public:
    int minCost(vector<int> &startPos, vector<int> &homePos, vector<int> &rowCosts, vector<int> &colCosts)
    {
        int srow = startPos[0], scol = startPos[1], hrow = homePos[0], hcol = homePos[1], ans = 0;
        if (srow <= hrow)
            for (int i = srow + 1; i <= hrow; i++)
                ans += rowCosts[i];
        else
            for (int i = srow - 1; i >= hrow; i--)
                ans += rowCosts[i];
        if (scol <= hcol)
            for (int i = scol + 1; i <= hcol; i++)
                ans += colCosts[i];
        else
            for (int i = scol - 1; i >= hcol; i--)
                ans += colCosts[i];
        return ans;
    }
};
// @lc code=end
