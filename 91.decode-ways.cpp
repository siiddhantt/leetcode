/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution
{
public:
    int numWays(int i, string &s, vector<int> &dp)
    {
        int res = 0;
        if (i >= s.length())
            return 1;
        if (dp[i] > 0)
            return dp[i];
        if (s[i] == '0')
            return 0;
        res += numWays(i + 1, s, dp);
        if ((i + 1 < s.length()) && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')))
            res += numWays(i + 2, s, dp);
        dp[i] = res;
        return res;
    }
    int numDecodings(string s)
    {
        int n = s.length();
        if (n == 1 && s == "0")
            return 0;
        vector<int> dp(n, 0);
        if (s[n - 1] != '0')
            dp[n - 1] = 1;
        numWays(0, s, dp);
        return dp[0];
    }
};
// @lc code=end
