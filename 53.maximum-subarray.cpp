/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int currsum = 0;
        int mxsum = nums[0];
        for (auto it : nums)
        {
            currsum += it;
            if (currsum > mxsum)
                mxsum = currsum;
            if (currsum < 0)
                currsum = 0;
        }
        return mxsum;
    }
};
// @lc code=end
