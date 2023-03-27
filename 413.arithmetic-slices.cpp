/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 */

// @lc code=start
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
            return 0;
        long long ans = 0, curr = 0, cdiff = nums[1] - nums[0];
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i + 1] - nums[i] == cdiff)
            {
                curr++;
                continue;
            }
            cdiff = nums[i + 1] - nums[i];
            if (curr >= 2)
            {
                curr -= 1;
                ans += (curr * (curr + 1)) / 2;
            }
            curr = 1;
        }
        if (curr >= 2)
        {
            curr -= 1;
            ans += (curr * (curr + 1)) / 2;
        }
        return ans;
    }
};
// @lc code=end
