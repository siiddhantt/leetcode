/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution
{
public:
    int helper(vector<int> &nums, vector<int> &dp, int index)
    {
        if (dp[index] != -1)
            return dp[index];
        int newmin = 100000;
        for (int i = 1; i <= nums[index]; i++)
        {
            if (index + i >= nums.size())
                break;
            newmin = min(newmin, 1 + helper(nums, dp, index + i));
        }
        return dp[index] = newmin;
    }
    int jump(vector<int> &nums)
    {
        vector<int> dp(nums.size(), -1);
        dp[nums.size() - 1] = 0;
        return helper(nums, dp, 0);
    }
};
// @lc code=end
