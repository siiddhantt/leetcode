/*
 * @lc app=leetcode id=1480 lang=cpp
 *
 * [1480] Running Sum of 1d Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        int s = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            s += nums[i];
            nums[i] = s;
        }
        return nums;
    }
};
// @lc code=end
