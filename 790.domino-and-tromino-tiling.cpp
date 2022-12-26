/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 */

// @lc code=start
class Solution
{
public:
    int mod = 1e9 + 7;
    int rec(int i, vector<int> &dp)
    {
        if (dp[i] != -1)
            return dp[i];
        if (i < 1)
            return 0;
        else if (i == 1 || i == 2)
            return i;
        else if (i == 3)
            return 5;
        int res = 0;
        res += ((2 * rec(i - 1, dp) % mod) + (rec(i - 3, dp) % mod)) % mod;
        return dp[i] = res;
    }
    int numTilings(int n)
    {
        vector<int> dp(n + 1, -1);
        return rec(n, dp);
    }
};
// @lc code=end
