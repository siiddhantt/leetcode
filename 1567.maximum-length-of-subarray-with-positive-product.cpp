/*
 * @lc app=leetcode id=1567 lang=cpp
 *
 * [1567] Maximum Length of Subarray With Positive Product
 */

// @lc code=start
class Solution
{
public:
    int length(vector<int> &nums)
    {
        int ans = 0, cou = 0, pro = 1;
        for (auto it : nums)
        {
            if (it != 0)
            {
                pro *= it / abs(it);
                cou++;
                if (pro > 0)
                    ans = max(ans, cou);
            }
            else
            {
                pro = 1;
                cou = 0;
            }
        }
        return ans;
    }
    int getMaxLen(vector<int> &nums)
    {
        int l1 = length(nums);
        reverse(nums.begin(), nums.end());
        int l2 = length(nums);
        return max(l1, l2);
    }
};
// @lc code=end
