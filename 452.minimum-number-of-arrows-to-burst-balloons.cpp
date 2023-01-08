/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end());
        int ans = 1, cur_l = points[0][0], cur_r = points[0][1];
        for (auto it : points)
        {
            if (it[0] > cur_r)
            {
                ans += 1;
                cur_l = it[0], cur_r = it[1];
            }
            else
            {
                cur_l = max(cur_l, it[0]);
                cur_r = min(cur_r, it[1]);
            }
        }
        return ans;
    }
};
// @lc code=end
