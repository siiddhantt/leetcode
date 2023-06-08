/*
 * @lc app=leetcode id=2134 lang=cpp
 *
 * [2134] Minimum Swaps to Group All 1's Together II
 */

// @lc code=start
class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int ones = 0, zeroes = 0;
        int n = nums.size(), l = 0, r = 0, ans;
        for (int i = 0; i < n; i++)
            if (nums[i] == 1)
                ones++;
        for (int i = 0; i < ones; i++)
            nums.push_back(nums[i]);
        n = nums.size();
        for (; r < ones; r++)
            if (nums[r] == 0)
                zeroes++;
        ans = zeroes;
        while (r < n - 1)
        {
            if (nums[r++] == 0)
                zeroes++;
            if (nums[l++] == 0)
                zeroes--;
            ans = min(ans, zeroes);
        }
        return ans;
    }
};
// @lc code=end
