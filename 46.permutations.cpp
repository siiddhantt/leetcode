/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> ans;
    void rec(vector<int> &nums, vector<int> &tmp, vector<int> &dp)
    {
        if (tmp.size() == nums.size())
        {
            ans.push_back(tmp);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (dp[i] == 0)
            {
                tmp.push_back(nums[i]);
                dp[i] = 1;
                rec(nums, tmp, dp);
                tmp.pop_back();
                dp[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 0), tmp;
        rec(nums, tmp, dp);
        return ans;
    }
};
// @lc code=end
