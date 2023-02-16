/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i + 1; j++)
            {
                int l = j - 1, r = j, val = INT_MAX;
                if (l >= 0)
                    val = min(val, triangle[i - 1][l]);
                if (r < i)
                    val = min(val, triangle[i - 1][r]);
                triangle[i][j] += val;
            }
        }
        int ans = INT_MAX;
        for (auto it : triangle.back())
            ans = min(ans, it);
        return ans;
    }
};
// @lc code=end
