/*
 * @lc app=leetcode id=713 lang=cpp
 *
 * [713] Subarray Product Less Than K
 */

// @lc code=start
class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int n = nums.size();
        int pro = 1, cou = 0, l = 0, r = 0;
        while (r < n)
        {
            pro *= nums[r];
            while (pro >= k && l <= r)
            {
                pro /= nums[l++];
            }
            cou += (r - l) + 1;
            r++;
        }
        return cou;
    }
};
// @lc code=end
