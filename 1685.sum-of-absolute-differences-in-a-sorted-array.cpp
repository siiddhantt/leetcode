/*
 * @lc app=leetcode id=1685 lang=cpp
 *
 * [1685] Sum of Absolute Differences in a Sorted Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> pf(n + 1, 0), sf(n + 1, 0), res;
        for (int i = 1; i <= n; i++)
        {
            pf[i] = pf[i - 1] + nums[i - 1];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            sf[i] = sf[i + 1] + nums[i];
        }
        for (int i = 0; i < n; i++)
        {
            int post = (n - 1 - i) * nums[i], pre = i * nums[i];
            int posum = (sf[i] - nums[i]) - post, presum = pre - pf[i];
            res.push_back(posum + presum);
        }
        return res;
    }
};
// @lc code=end
