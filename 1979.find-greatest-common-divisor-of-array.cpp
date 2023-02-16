/*
 * @lc app=leetcode id=1979 lang=cpp
 *
 * [1979] Find Greatest Common Divisor of Array
 */

// @lc code=start
class Solution
{
public:
    int findGCD(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int a = nums[0], b = nums[nums.size() - 1];
        return gcd(a, b);
    }
};
// @lc code=end
