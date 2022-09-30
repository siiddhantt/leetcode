/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        int m;
        while (l < r)
        {
            m = l + (r - l) / 2;

            if (nums[m] == target)
            {
                return m;
            }

            if (nums[m] < target)
            {
                l = m + 1;
            }

            else
            {
                r = m - 1;
            }
        }

        if (l == r)
        {
            if (nums[l] == target)
            {
                m = l;
            }

            else
            {
                if (target > nums[l])
                {
                    m = l + 1;
                }
                else
                {
                    m = l;
                }
            }
        }

        return m;
    }
};
// @lc code=end
