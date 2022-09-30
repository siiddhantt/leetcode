/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
 */

// @lc code=start
class Solution
{
public:
    int maxSum(vector<int> &arr, int i)
    {
        int csum = 0, fsum = INT_MIN;
        for (int i = 0; i < arr.size(); i++)
        {
            csum += arr[i];
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
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int n = nums.size();
        int i = n - 1, csum = 0, s2 = 0;
        int s1 = maxSum(nums, 0);
        if (s1 < 0)
        {
            return s1;
        }
        for (int i = 0; i < n; i++)
        {
            csum += nums[i];
            nums[i] = -nums[i];
        }
        s2 = csum + maxSum(nums, 0);
        return max(s1, s2);
    }
};
// @lc code=end
