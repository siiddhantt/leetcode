/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution
{
public:
    int rec(string &text1, int i, string &text2, int j, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (text1[i] == text2[j])
            return dp[i][j] = 1 + rec(text1, i - 1, text2, j - 1, dp);
        return dp[i][j] = max(rec(text1, i - 1, text2, j, dp), rec(text1, i, text2, j - 1, dp));
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return rec(text1, n - 1, text2, m - 1, dp);
    }
};
// @lc code=end
