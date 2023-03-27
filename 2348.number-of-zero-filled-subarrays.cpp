/*
 * @lc app=leetcode id=2348 lang=cpp
 *
 * [2348] Number of Zero-Filled Subarrays
 */

// @lc code=start
class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        int n = nums.size();
        long long ans = 0, curr = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                curr++;
                continue;
            }
            ans += (curr * (curr + 1)) / 2;
            curr = 0;
        }
        ans += (curr * (curr + 1)) / 2;
        return ans;
    }
};
// @lc code=end
