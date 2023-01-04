/*
 * @lc app=leetcode id=1827 lang=cpp
 *
 * [1827] Minimum Operations to Make the Array Increasing
 */

// @lc code=start
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] < nums[i + 1])
                continue;
            ans += nums[i] + 1 - nums[i + 1];
            nums[i + 1] = nums[i] + 1;
        }
        return ans;
    }
};
// @lc code=end
