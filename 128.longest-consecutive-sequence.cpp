/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return 1;
        sort(nums.begin(), nums.end());
        int ans = 1, curr = 1;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if ((nums[i + 1] - nums[i]) == 1)
                curr += 1;
            else if ((nums[i + 1] - nums[i]) == 0)
                continue;
            else
                curr = 1;
            ans = max(ans, curr);
        }
        return ans;
    }
};
// @lc code=end
