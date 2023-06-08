/*
 * @lc app=leetcode id=775 lang=cpp
 *
 * [775] Global and Local Inversions
 */

// @lc code=start
class Solution
{
public:
    bool isIdealPermutation(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (abs(nums[i] - i) > 1)
                return false;
        }
        return true;
    }
};
// @lc code=end
