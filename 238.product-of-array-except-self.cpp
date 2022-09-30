/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> pf(n + 1, 1), sf(n + 2, 1), res;
        for (int i = 2; i <= n; i++)
        {
            pf[i] = nums[i - 2] * pf[i - 1];
        }
        for (int i = n - 1; i >= 1; i--)
        {
            sf[i] = nums[i] * sf[i + 1];
        }
        for (int i = 1; i <= n; i++)
        {
            res.push_back(pf[i] * sf[i]);
        }
        return res;
    }
};
// @lc code=end
