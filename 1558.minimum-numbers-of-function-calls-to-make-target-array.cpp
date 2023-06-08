/*
 * @lc app=leetcode id=1558 lang=cpp
 *
 * [1558] Minimum Numbers of Function Calls to Make Target Array
 */

// @lc code=start
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size(), ones = 0, twos = 0;
        for (int i = 0; i < n; i++)
        {
            int tmp = 0;
            while (nums[i])
            {
                tmp++;
                if (nums[i] & 1)
                    ones++;
                nums[i] >>= 1;
            }
            twos = max(twos, tmp);
        }
        return ones + twos - 1;
    }
};
// @lc code=end
