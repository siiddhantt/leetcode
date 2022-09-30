/*
 * @lc app=leetcode id=1732 lang=cpp
 *
 * [1732] Find the Highest Altitude
 */

// @lc code=start
class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int n = gain.size(), maxh = 0;
        vector<int> pf(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            pf[i] = pf[i - 1] + gain[i - 1];
            maxh = max(maxh, pf[i]);
        }
        return maxh;
    }
};
// @lc code=end
