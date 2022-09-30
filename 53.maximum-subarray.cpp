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
        int fsum = nums[0];
        int csum = 0;
        vector<int>::iterator iter;
        for (iter = nums.begin(); iter != nums.end(); ++iter)
        {
            csum += *iter;
            if (csum > fsum)
            {
                fsum = csum;
            }
            if (csum < 0)
            {
                csum = 0;
            }
        }
        return fsum;
    }
};
// @lc code=end
