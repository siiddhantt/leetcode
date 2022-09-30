/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */

// @lc code=start
class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size(), sum = 0;
        unordered_map<int, int> m;
        m[0] = -1;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            int rem = sum % k;
            if (m.find(rem) == m.end())
                m[rem] = i;
            else if (i - m[rem] > 1)
                return true;
        }
        return false;
    }
};
// @lc code=end
