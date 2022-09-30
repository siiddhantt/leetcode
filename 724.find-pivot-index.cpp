/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

// @lc code=start
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int s1 = 0;
        int s2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            s1 += nums[i];
            if (i == 0 || i == (nums.size() - 1))
            {
                if (nums.size() == 1)
                {
                    return 0;
                }
                else if (i == 0)
                {
                    s2 = accumulate(nums.begin() + (i + 1), nums.end(), 0);
                    if (s2 == 0)
                    {
                        return 0;
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    s2 = accumulate(nums.begin(), nums.end() - 1, 0);
                    if (s2 == 0)
                    {
                        return (nums.size() - 1);
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            s2 = accumulate(nums.begin() + (i + 1), nums.end(), 0);
            if ((s1 - nums[i]) == s2)
            {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end
