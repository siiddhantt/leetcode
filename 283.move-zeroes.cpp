/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int pos = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[pos] == 0)
            {
                nums.erase(nums.begin() + pos);
                nums.push_back(0);
            }
            else
            {
                pos += 1;
            }
        }
    }
};
// @lc code=end
