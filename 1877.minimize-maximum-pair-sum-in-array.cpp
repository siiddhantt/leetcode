/*
 * @lc app=leetcode id=1877 lang=cpp
 *
 * [1877] Minimize Maximum Pair Sum in Array
 */

// @lc code=start
class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1, s = 0;
        sort(nums.begin(), nums.end());
        while (l <= r)
        {
            s = max(s, nums[l] + nums[r]);
            l++;
            r--;
        }
        return s;
    }
};
// @lc code=end
