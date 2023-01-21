/*
 * @lc app=leetcode id=926 lang=cpp
 *
 * [926] Flip String to Monotone Increasing
 */

// @lc code=start
class Solution
{
public:
    int rec(int i, string &s, vector<int> &ones, vector<int> &dp)
    {
        if (i < 0)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int ans;
        if (s[i] == '0')
        {
            int l = ones[i];
            int r = 1 + rec(i - 1, s, ones, dp);
            ans = min(l, r);
        }
        else
        {
            int l = rec(i - 1, s, ones, dp);
            int r = ones[i];
            ans = min(l, r);
        }
        return dp[i] = ans;
    }
    int minFlipsMonoIncr(string s)
    {
        int n = s.size();
        vector<int> ones(n, 0), dp(n, -1);
        if (s[0] == '1')
            ones[0]++;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == '1')
                ones[i] = ones[i - 1] + 1;
            else
                ones[i] = ones[i - 1];
        }
        return rec(n - 1, s, ones, dp);
    }
};
// @lc code=end
