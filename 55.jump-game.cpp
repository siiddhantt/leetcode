/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size(), least = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] >= least)
            {
                least = 1;
                continue;
            }
            least++;
        }
        if (least == 1)
            return true;
        return false;
    }
};
// @lc code=end
