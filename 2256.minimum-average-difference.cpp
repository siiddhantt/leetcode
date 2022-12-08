/*
 * @lc app=leetcode id=2256 lang=cpp
 *
 * [2256] Minimum Average Difference
 */

// @lc code=start
class Solution
{
public:
    int minimumAverageDifference(vector<int> &nums)
    {
        int n = nums.size(), ans;
        vector<long long> lsum(n + 1, 0), rsum(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            lsum[i] = nums[i - 1] + lsum[i - 1];
            rsum[n - i] = nums[n - i] + rsum[n + 1 - i];
        }
        int mindiff = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            int avdiff;
            if (i == n)
                avdiff = (lsum[i] / i);
            else
                avdiff = abs((lsum[i] / i) - (rsum[i] / (n - i)));
            if (avdiff < mindiff)
            {
                ans = i - 1;
                mindiff = avdiff;
            }
            else if (avdiff == mindiff)
                ans = min(ans, i - 1);
        }
        return ans;
    }
};
// @lc code=end
