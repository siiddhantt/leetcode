/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start
class Solution
{
public:
    int rec_cou(vector<int> &nums, int t, vector<int> &dp)
    {
        if (t < 0)
            return 0;
        if (t == 0)
            return 1;
        if (dp[t] != -1)
            return dp[t];
        int cou = 0;
        for (int i = 0; i < nums.size(); i++)
            cou += rec_cou(nums, t - nums[i], dp);
        return dp[t] = cou;
    }
    int combinationSum4(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> dp(target + 1, -1);
        return rec_cou(nums, target, dp);
    }
};
// @lc code=end
