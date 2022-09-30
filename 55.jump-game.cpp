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
        int n = nums.size();
        vector<int> dp(n, -1);
        for (int i = n - 1; i >= 0; i--)
        {
            if (dp[i] == -1)
            {
                if (nums[i] >= (n - 1 - i))
                {
                    dp[i] = 1;
                }
                else
                {
                    if (nums[i] == 0)
                    {
                        dp[i] = 0;
                    }
                    else
                    {
                        for (int j = i + 1; j <= i + nums[i]; j++)
                        {
                            if (dp[j] == 1)
                            {
                                dp[i] = 1;
                            }
                        }
                        if (dp[i] != 1)
                        {
                            dp[i] = 0;
                        }
                    }
                }
            }
        }
        return (dp[0] == 1);
    }
};
// @lc code=end
