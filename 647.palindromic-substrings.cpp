/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution
{
public:
    bool isPal(string &s, int i, int j, vector<vector<bool>> &dp)
    {
        if (dp[i][j] != NULL)
            return dp[i][j];
        if (i == j)
            return true;
        else if (j == i + 1)
            return s[i] == s[j];
        dp[i][j] = (s[i] == s[j]) && (isPal(s, i + 1, j - 1, dp));
        return dp[i][j];
    }
    int countSubstrings(string s)
    {
        int n = s.size(), ans = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, NULL));
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (isPal(s, i, j, dp) == true)
                    ans++;
            }
        }
        return ans;
    }
};
// @lc code=end
